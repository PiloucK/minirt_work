/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 15:56:59 by clkuznie          #+#    #+#             */
/*   Updated: 2020/10/09 19:51:00 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void
    ray_bounce(t_ray *ray, t_info *info, t_elem_list *hit_elem)
{
    if (hit_elem)
    {
        ray->color = (*(t_sphere *)(hit_elem->elem_detail)).color.r;
        ray->color = (ray->color << 8) + (*(t_sphere *)(hit_elem->elem_detail)).color.g;
        ray->color = (ray->color << 8) + (*(t_sphere *)(hit_elem->elem_detail)).color.b;
    }
    else
    {
        ray->color = info->ambiant->color.r * info->ambiant->lum;
        ray->color = (ray->color << 8) + info->ambiant->color.g * info->ambiant->lum;
        ray->color = (ray->color << 8) + info->ambiant->color.b * info->ambiant->lum;
    }
}

static void
    find_closest(t_ray *ray, t_info *info, double closest)
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
    ray_bounce(ray, info, closest_elem);
    return ;
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
            find_closest(&ray, info, 1000000000);
            pixel_color = info->image.data +
                ((int)y * info->image.line_len +
                (int)x * (info->image.bits_per_pixel / 8));
            *(unsigned int *)pixel_color = ray.color;
            camera_ray_gen(&ray, info, x + 0.5, y);
            find_closest(&ray, info, 1000000000);
            pixel_color = info->image.data +
                ((int)y * info->image.line_len +
                (int)x * (info->image.bits_per_pixel / 8));
            *(unsigned int *)pixel_color = (ray.color + *(unsigned int *)pixel_color) / 2;
            camera_ray_gen(&ray, info, x, y + 0.5);
            find_closest(&ray, info, 1000000000);
            pixel_color = info->image.data +
                ((int)y * info->image.line_len +
                (int)x * (info->image.bits_per_pixel / 8));
            *(unsigned int *)pixel_color = (ray.color + *(unsigned int *)pixel_color) / 2;
            camera_ray_gen(&ray, info, x + 0.5, y + 0.5);
            find_closest(&ray, info, 1000000000);
            pixel_color = info->image.data +
                ((int)y * info->image.line_len +
                (int)x * (info->image.bits_per_pixel / 8));
            *(unsigned int *)pixel_color = (ray.color + *(unsigned int *)pixel_color) / 2;
            y++;
        }
        x++;
    }
}
