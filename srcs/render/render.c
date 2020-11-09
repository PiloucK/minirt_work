/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 15:56:59 by clkuznie          #+#    #+#             */
/*   Updated: 2020/11/09 21:04:26 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double
    my_min(double a, double b)
{
    if (a > b)
        return (b);
    return (a);
}

double
    my_max(double a, double b)
{
    if (a < b)
        return (b);
    return (a);
}

// double
//     fast_clamp(double nb, double min, double max)
// {
//     int  dif;
//     int  dif_sign;

//     dif = nb - min;
//     dif_sign = dif >> 31;
//     nb = nb - (dif & dif_sign);
//     dif = nb - max;
//     dif_sign = dif >> 31;
//     return (nb + (dif & dif_sign));
// }

double
    my_clamp(double nb, double min, double max)
{
    nb = my_max(nb, min);
    return (my_min(nb, max));
}

t_color
    colormult(t_color color, double ratio)
{
    color.r *= ratio;
    color.g *= ratio;
    color.b *= ratio;
    return (color);
}

int
    coloradd(t_color *color, t_color ratio)
{
    color->r = my_clamp(color->r + ratio.r, 0, 1);
    color->g = my_clamp(color->g + ratio.g, 0, 1);
    color->b = my_clamp(color->b + ratio.b, 0, 1);
    return (!((color->r != 1) + (color->g != 1) + (color->b != 1)));
}

int
    colorsub(t_color *color, t_color ratio)
{
    color->r = my_clamp(color->r * ratio.r, 0, 1);
    color->g = my_clamp(color->g * ratio.g, 0, 1);
    color->b = my_clamp(color->b * ratio.b, 0, 1);
    return (!((color->r != 1) + (color->g != 1) + (color->b != 1)));
}

void
    ray_bounce(t_ray *ray, t_info *info, t_elem_list *hit_elem, int *i)
{
    t_light_list    *cur_light;
    t_color         lights_sum;
    t_ray           bounce;

    if (--*i >= 0 && hit_elem)
    {
        lights_sum = colormult(info->ambiant->color, info->ambiant->ratio);
        bounce.pos = vectranslat(ray->bounce.pos, ray->bounce.n, 0);
        cur_light = info->first_light;
        while (cur_light)
        {
            bounce.dir = vecnorm(vecnew(bounce.pos, cur_light->pos));
            if (find_closest(&bounce, info,
                vecmag(vecnew(bounce.pos, cur_light->pos)) - EPSY, *i))
            {
                if (coloradd(&lights_sum,
                    colormult(colormult(cur_light->color, cur_light->ratio),
                    my_clamp(vecdotprod(bounce.dir, ray->bounce.n), 0, 1))))
                    break ;
            }
            cur_light = cur_light->next_light;
        }
        colorsub(&(ray->color), lights_sum);
    }
    else
        ray->color = colormult(ray->color, 0);
}

int
    find_closest(t_ray *ray, t_info *info, double closest, int i)
{
    t_elem_list     *cur_elem;
    t_elem_list     *closest_elem;
    
    cur_elem = info->first_elem;
    closest_elem = NULL;
    while (cur_elem)
    {
        closest_elem =
            (*intersect_arr[cur_elem->id])(&closest, ray, cur_elem->elem_detail)
            ? cur_elem : closest_elem;
        cur_elem = cur_elem->next_elem;
    }
    if (i)
        ray_bounce(ray, info, closest_elem, &i);
    return (!closest_elem);
}

void
    screen_scan(t_info *info)
{
    t_ray   ray;
    int     x;
    int     y;
    char *pixel_color;
    unsigned int    *pc;

    x = 160;
    intersect_arr_init();
    while (x < 170)
    {
        y = 380;
        while (y < 390)
        {
            camera_ray_gen(&ray, info, x, y);
            find_closest(&ray, info, 1000000000, MAX_DEPTH);
            pixel_color = info->image.data +
                (y * info->image.line_len +
                x * (info->image.bits_per_pixel / 8));
            pc = (unsigned int *)pixel_color;
            *pc = ray.color.r * 255;
            *pc = (*pc << 8) + ray.color.g * 255;
            *pc = (*pc << 8) + ray.color.b * 255;
            y++;
        }
        x++;
    }
}

void
    chunk_fill(t_color color, t_info *info, int x, int y)
{
    int     i;
    int     j;
    char    *pixel_address;
    unsigned int    *pixel;

    i = 0;
    while (i < REDUC && x + i < info->res->x)
    {
        j = 0;
        while (j < REDUC && y + j < info->res->y)
        {
            pixel_address = info->image.data +
            ((y + j) * info->image.line_len +
            (x + i) * (info->image.bits_per_pixel / 8));
            pixel = (unsigned int *)pixel_address;
            *pixel = color.r * 255;
            *pixel = (*pixel << 8) + color.g * 255;
            *pixel = (*pixel << 8) + color.b * 255;
            j++;
        }
        i++;
    }
}

void
    pre_render(t_info *info)
{
    t_ray           ray;
    int             x;
    int             y;

    x = 0;
    intersect_arr_init();
    while (x < info->res->x + REDUC)
    {
        y = 0;
        while (y < info->res->y + REDUC)
        {
            camera_ray_gen(&ray, info, x + REDUC / 2, y + REDUC / 2);
            find_closest(&ray, info, 1000000000, MAX_DEPTH);
            chunk_fill(ray.color, info, x, y);
            y += REDUC;
        }
        x += REDUC;
    }
}

void
    test_scan(t_info *info)
{
    t_ray   ray;
    int     x;
    int     y;
    char *pixel_color;
    unsigned int    *pc;

    x = 470;
    intersect_arr_init();
    while (x < 520)
    {
        y = 150;
        while (y < 190)
        {
            camera_ray_gen(&ray, info, x, y);
            find_closest(&ray, info, 1000000000, MAX_DEPTH);
            pixel_color = info->image.data +
                (y * info->image.line_len +
                x * (info->image.bits_per_pixel / 8));
            pc = (unsigned int *)pixel_color;
            *pc = ray.color.r * 255;
            *pc = (*pc << 8) + ray.color.g * 255;
            *pc = (*pc << 8) + ray.color.b * 255;
            y++;
        }
        x++;
    }
}
