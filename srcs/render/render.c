/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 15:56:59 by clkuznie          #+#    #+#             */
/*   Updated: 2020/10/12 15:36:59 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void
    prefill_ambiant(t_info *info)
{
    int     x;
    int     y;
    char    *pixel_color;
    int     color;

    color = info->ambiant->color.r * info->ambiant->ratio;
    color = (color << 8) + info->ambiant->color.g * info->ambiant->ratio;
    color = (color << 8) + info->ambiant->color.b * info->ambiant->ratio;
    x = 0;
    while (x < info->res->x)
    {
        y = 0;
        while (y < info->res->y)
        {
            pixel_color = info->image.data +
                ((int)y * info->image.line_len +
                (int)x * (info->image.bits_per_pixel / 8));
            *(unsigned int *)pixel_color = color;
            y++;
        }
        x++;
    }
}

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
    ray_bounce(t_ray *ray, t_info *info, t_elem_list *hit_elem, double closest, int *i)
{
    t_elem_list     *cur_elem;
    t_vec3lf        origin;
    t_light         *cur_light;
    int             light_participation;
    t_color         final_color;

    (void)closest;
    (void)cur_elem;
    (void)cur_light;
    (void)light_participation;
    (void)origin;
    (void)info;
    *i += 1;
    if (hit_elem)
    {
        final_color = (*(t_sphere *)(hit_elem->elem_detail)).color;
        origin = vectranslat(ray->pos, ray->dir, closest);
        cur_elem = info->first_elem;
        while (cur_elem)
        {
            if (cur_elem->id == L)
            {
                ray->pos = origin;
                ray->dir = vecnorm(vecnew(origin, (*(t_light *)(cur_elem->elem_detail)).pos));
                if (find_closest(ray, info, vecmag(vecnew(origin, (*(t_light *)(cur_elem->elem_detail)).pos)), *i) == vecmag(vecnew(origin, (*(t_light *)(cur_elem->elem_detail)).pos)))
                {
                    final_color.r = my_min(
                        255.0,
                        ((final_color.r / 255) * my_max(
                            255.0,
                            ((((*(t_light *)(cur_elem->elem_detail)).color.r * (*(t_light *)(cur_elem->elem_detail)).ratio) / 255 / (vecmag(vecnew(origin, (*(t_light *)(cur_elem->elem_detail)).pos)) * vecmag(vecnew(origin, (*(t_light *)(cur_elem->elem_detail)).pos)))) + (info->ambiant->color.r * info->ambiant->ratio / 255))) * 255));
                    final_color.g = my_min(
                        255.0,
                        ((final_color.g / 255) * my_max(
                            255.0,
                            ((((*(t_light *)(cur_elem->elem_detail)).color.g * (*(t_light *)(cur_elem->elem_detail)).ratio) / 255 / (vecmag(vecnew(origin, (*(t_light *)(cur_elem->elem_detail)).pos)) * vecmag(vecnew(origin, (*(t_light *)(cur_elem->elem_detail)).pos)))) + (info->ambiant->color.g * info->ambiant->ratio / 255))) * 255));
                    final_color.b = my_min(
                        255.0,
                        ((final_color.b / 255) * my_max(
                            255.0,
                            ((((*(t_light *)(cur_elem->elem_detail)).color.b * (*(t_light *)(cur_elem->elem_detail)).ratio) / 255 / (vecmag(vecnew(origin, (*(t_light *)(cur_elem->elem_detail)).pos)) * vecmag(vecnew(origin, (*(t_light *)(cur_elem->elem_detail)).pos)))) + (info->ambiant->color.b * info->ambiant->ratio / 255))) * 255));
                    ray->color = final_color.r;
                    ray->color = (ray->color << 8) + final_color.g;
                    ray->color = (ray->color << 8) + final_color.b;
                }
                else
                {
                    final_color.r = my_min(255.0, ((final_color.r / 255) * (info->ambiant->color.r * info->ambiant->ratio / 255)) * 255);
                    final_color.g = my_min(255.0, ((final_color.g / 255) * (info->ambiant->color.r * info->ambiant->ratio / 255)) * 255);
                    final_color.b = my_min(255.0, ((final_color.b / 255) * (info->ambiant->color.r * info->ambiant->ratio / 255)) * 255);
                    ray->color = final_color.r;
                    ray->color = (ray->color << 8) + final_color.g;
                    ray->color = (ray->color << 8) + final_color.b;
                }
            }
            cur_elem = cur_elem->next_elem;
        }
    }
    else
    {
        ray->color = info->ambiant->color.r * info->ambiant->ratio;
        ray->color = (ray->color << 8) + info->ambiant->color.g * info->ambiant->ratio;
        ray->color = (ray->color << 8) + info->ambiant->color.b * info->ambiant->ratio;
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
    if (i < 1)
        ray_bounce(ray, info, closest_elem, closest, &i);
    return (closest);
}

void
    screen_scan(t_info *info)
{
    t_ray   ray;
    double     x;
    double     y;
    char *pixel_color;

    x = 0;
    intersect_arr_init();
    while (x < info->res->x)
    {
        y = 0;
        while (y < info->res->y)
        {
            camera_ray_gen(&ray, info, x, y);
            find_closest(&ray, info, 1000000000, 0);
            pixel_color = info->image.data +
                ((int)y * info->image.line_len +
                (int)x * (info->image.bits_per_pixel / 8));
            *(unsigned int *)pixel_color = ray.color;
            // camera_ray_gen(&ray, info, x + 0.5, y);
            // find_closest(&ray, info, 1000000000, 0);
            // pixel_color = info->image.data +
            //     ((int)y * info->image.line_len +
            //     (int)x * (info->image.bits_per_pixel / 8));
            // *(unsigned int *)pixel_color = (ray.color + *(unsigned int *)pixel_color) / 2;
            // camera_ray_gen(&ray, info, x, y + 0.5);
            // find_closest(&ray, info, 1000000000, 0);
            // pixel_color = info->image.data +
            //     ((int)y * info->image.line_len +
            //     (int)x * (info->image.bits_per_pixel / 8));
            // *(unsigned int *)pixel_color = (ray.color + *(unsigned int *)pixel_color) / 2;
            // camera_ray_gen(&ray, info, x + 0.5, y + 0.5);
            // find_closest(&ray, info, 1000000000, 0);
            // pixel_color = info->image.data +
            //     ((int)y * info->image.line_len +
            //     (int)x * (info->image.bits_per_pixel / 8));
            // *(unsigned int *)pixel_color = (ray.color + *(unsigned int *)pixel_color) / 2;
            y++;
        }
        x++;
    }
}
