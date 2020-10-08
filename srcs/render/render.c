/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 15:56:59 by clkuznie          #+#    #+#             */
/*   Updated: 2020/10/08 18:45:46 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static double
    find_closest(t_ray *ray, t_info *info)
{
    t_elem_list     *cur_elem;
    double          closest;
    
    cur_elem = info->first_elem;
    closest = 1000000000;
    ray->color = info->ambiant->color.r * info->ambiant->lum;
    ray->color = (ray->color << 8) + info->ambiant->color.g * info->ambiant->lum;
    ray->color = (ray->color << 8) + info->ambiant->color.b * info->ambiant->lum;
    while (cur_elem)
    {
        closest = (*intersect_arr[cur_elem->id])(closest, ray, cur_elem->elem_detail);
        cur_elem = cur_elem->next_elem;
    }
    // printf("closest = %lf\n", closest);
    return (closest);
}

void
    screen_scan(t_info *info)
{
    int     x;
    int     y;
    t_ray   ray;

    x = 0;
    ray.pos = info->cur_camera->pos;
    ray.dir = info->cur_camera->dir;
    // ray_gen(&ray, info);
    // img_ptr = mlx_new_image(info->mlx, info->res->x, info->res->y);
    intersect_arr_init();

    // char *data;
    // int bits_per_pixel, line_length, endian;
    char *dest;
    // data = mlx_get_data_addr(img_ptr, &bits_per_pixel, &line_length,
    //                             &endian);
    while (x < info->res->x)
    {
        y = 0;
        while (y < info->res->y)
        {
            ray.pos.x = x;
            ray.pos.y = y;
            find_closest(&ray, info);
            dest = info->image.data +
                (y * info->image.line_len +
                x * (info->image.bits_per_pixel / 8));
            *(unsigned int *)dest = ray.color;
            y++;
        }
        x++;
    }
    // if (!info->do_save)
    //     mlx_put_image_to_window (info->mlx, info->win, info->image.img, 0, 0);
}
