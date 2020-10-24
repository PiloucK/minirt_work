/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 15:56:59 by clkuznie          #+#    #+#             */
/*   Updated: 2020/10/25 00:41:40 by clkuznie         ###   ########.fr       */
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
    t_color         final_color;
    double          light_dist;
    double          light_angle;

    *i -= 1;
    if (hit_elem)
    {
        final_color = ray->color;
        cur_elem = info->first_elem;
        while (cur_elem)
        {
            if (cur_elem->id == L)
            {
                cur_light = (t_light *)(cur_elem->elem_detail);
                ray->pos = vectranslat(ray->bounce.pos, ray->bounce.surface_normal, 0.1);
                ray->dir = vecnorm(vecnew(ray->pos, cur_light->pos));
                light_dist = vecmag(vecnew(ray->pos, cur_light->pos));
                if (find_closest(ray, info, light_dist, *i) != light_dist)
                {
                    // final_color.r = my_clamp((final_color.r * info->ambiant->color.r * info->ambiant->ratio), 0, 1);
                    // final_color.g = my_clamp((final_color.g * info->ambiant->color.g * info->ambiant->ratio), 0, 1);
                    // final_color.b = my_clamp((final_color.b * info->ambiant->color.b * info->ambiant->ratio), 0, 1);
                    final_color.r = 0;
                    final_color.g = 0;
                    final_color.b = 0;
                    ray->color = final_color;
                }
                else
                {
                    // printf("%lf\n", cos(vecangle(ray->dir, ray->bounce.surface_normal) / (PI / 180)));
                    light_angle = vecangle(ray->dir, ray->bounce.surface_normal);
                    final_color.r = my_clamp(
                        ((final_color.r) * my_clamp(
                            (((cur_light->color.r * cur_light->ratio) * cos(light_angle)) + (info->ambiant->color.r * info->ambiant->ratio)), 0, 1)), 0, 1);
                    final_color.g = my_clamp(
                        ((final_color.g) * my_clamp(
                            (((cur_light->color.g * cur_light->ratio) * cos(light_angle)) + (info->ambiant->color.g * info->ambiant->ratio)), 0, 1)), 0, 1);
                    final_color.b = my_clamp(
                        ((final_color.b) * my_clamp(
                            (((cur_light->color.b * cur_light->ratio) * cos(light_angle)) + (info->ambiant->color.b * info->ambiant->ratio)), 0, 1)), 0, 1);
                    ray->color = final_color;
                }
            }
            cur_elem = cur_elem->next_elem;
        }
    }
    else
    {
        ray->color.r = info->ambiant->color.r * info->ambiant->ratio;
        ray->color.g = info->ambiant->color.g * info->ambiant->ratio;
        ray->color.b = info->ambiant->color.b * info->ambiant->ratio;
    }
}

double
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
    return (closest);
}

void
    screen_scan(t_info *info)
{
    // printf("%lf\n%lf\n%lf\n%lf\n%lf\n", my_clamp(0.3, 0, 1),
    // my_clamp(-0.3, 0, 1),
    // my_clamp(1.3, 0, 1),
    // my_clamp(1, 0, 1),
    // my_clamp(0, 0, 1));
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
    test_scan(t_info *info)
{
    t_ray   ray;
    int     x;
    int     y;
    char *pixel_color;
    unsigned int    *pc;

    x = 0;
    intersect_arr_init();
    while (x < 1)
    {
        y = 0;
        while (y < 1)
        {
            printf("%i\n", x);
            printf("%i\n", y);
            camera_ray_gen(&ray, info, x, y);
            print_vec3lf(ray.dir);
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
