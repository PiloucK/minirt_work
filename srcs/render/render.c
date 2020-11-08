/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 15:56:59 by clkuznie          #+#    #+#             */
/*   Updated: 2020/11/08 18:17:40 by user42           ###   ########.fr       */
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

double
    fast_clamp(double nb, double min, double max)
{
    int  dif;
    int  dif_sign;

    dif = nb - min;
    dif_sign = dif >> 31;
    nb = nb - (dif & dif_sign);
    dif = nb - max;
    dif_sign = dif >> 31;
    return (nb + (dif & dif_sign));
}

double
    my_clamp(double nb, double min, double max)
{
    nb = my_max(nb, min);
    return (my_min(nb, max));
}

void
    ray_bounce(t_ray *ray, t_info *info, t_elem_list *hit_elem, int *i)
{
    t_elem_list     *cur_elem;
    t_light         *cur_light;
    t_color         lights_sum;
    double          light_dist;
    double          energy;
    t_ray           bounce;

    *i -= 1;
    if (hit_elem)
    {
        lights_sum.r = my_clamp(info->ambiant->color.r * info->ambiant->ratio, 0, 1);
        lights_sum.g = my_clamp(info->ambiant->color.g * info->ambiant->ratio, 0, 1);
        lights_sum.b = my_clamp(info->ambiant->color.b * info->ambiant->ratio, 0, 1);
        bounce.pos = vectranslat(ray->bounce.pos, ray->bounce.surface_normal, 0);
        cur_elem = info->first_elem;
        while (cur_elem)
        {
            if (cur_elem->id == L)
            {
                cur_light = (t_light *)(cur_elem->elem_detail);
                bounce.dir = vecnorm(vecnew(bounce.pos, cur_light->pos));
                light_dist = vecmag(vecnew(bounce.pos, cur_light->pos));
                if (find_closest(&bounce, info, light_dist, *i))
                {
                    energy = my_clamp(vecdotprod(bounce.dir, ray->bounce.surface_normal), 0, 1);
                    lights_sum.r += my_clamp((cur_light->color.r * cur_light->ratio) * energy, 0, 1);
                    lights_sum.g += my_clamp((cur_light->color.g * cur_light->ratio) * energy, 0, 1);
                    lights_sum.b += my_clamp((cur_light->color.b * cur_light->ratio) * energy, 0, 1);
                }
            }
            cur_elem = cur_elem->next_elem;
        }
        ray->color.r = my_clamp(lights_sum.r * ray->color.r, 0, 1);
        ray->color.g = my_clamp(lights_sum.g * ray->color.g, 0, 1);
        ray->color.b = my_clamp(lights_sum.b * ray->color.b, 0, 1);
    }
    else
    {
        ray->color.r = 0;
        ray->color.g = 0;
        ray->color.b = 0;
    }
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

    x = 0;
    intersect_arr_init();
    while (x < info->res->x)
    {
        y = 0;
        while (y < info->res->y)
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
