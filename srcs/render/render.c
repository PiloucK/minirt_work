/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 15:56:59 by clkuznie          #+#    #+#             */
/*   Updated: 2020/10/20 16:32:00 by clkuznie         ###   ########.fr       */
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

void
    ray_bounce(t_ray *ray, t_info *info, t_elem_list *hit_elem, int *i)
{
    t_elem_list     *cur_elem;
    t_light         *cur_light;
    t_color         final_color;
    double          light_dist;

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
                // printf("light_dist = %lf\n", light_dist);
                // printf("light_dist = %lf\n", find_closest(ray, info, light_dist, *i));
                if (find_closest(ray, info, light_dist, *i) != light_dist)
                {
                    final_color.r = my_min(1, ((final_color.r) * (info->ambiant->color.r * info->ambiant->ratio)));
                    final_color.g = my_min(1, ((final_color.g) * (info->ambiant->color.g * info->ambiant->ratio)));
                    final_color.b = my_min(1, ((final_color.b) * (info->ambiant->color.b * info->ambiant->ratio)));
                    ray->color = final_color;
                }
                else
                {
                    final_color.r = my_min(
                        1,
                        ((final_color.r) * my_max(
                            1,
                            (((cur_light->color.r * cur_light->ratio) / (light_dist * light_dist)) + (info->ambiant->color.r * info->ambiant->ratio)))));
                    final_color.g = my_min(
                        1,
                        ((final_color.g) * my_max(
                            1,
                            (((cur_light->color.g * cur_light->ratio) / (light_dist * light_dist)) + (info->ambiant->color.g * info->ambiant->ratio)))));
                    final_color.b = my_min(
                        1,
                        ((final_color.b) * my_max(
                            1,
                            (((cur_light->color.b * cur_light->ratio) / (light_dist * light_dist)) + (info->ambiant->color.b * info->ambiant->ratio)))));
                    // final_color.r *= cur_light->color.r;
                    // final_color.g *= cur_light->color.g;
                    // final_color.b *= cur_light->color.b;
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
