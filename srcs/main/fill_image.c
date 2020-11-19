/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 23:28:47 by user42            #+#    #+#             */
/*   Updated: 2020/11/19 11:04:47 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void
    chunk_fill(t_color color, t_info *info, int x, int y)
{
    int     i;
    int     j;
    char    *pixel_address;
    unsigned int    *pixel;

    i = 0;
    while (i < info->various.reduc && x + i < info->res->x)
    {
        j = 0;
        while (j < info->various.reduc && y + j < 1)
        {
            pixel_address = info->image.data +
            ((y + j) * info->image.line_len +
            (x + i) * (info->image.bits_per_pixel / 8));
            pixel = (unsigned int *)pixel_address;
            *pixel = color.r * 255;
            *pixel = (*pixel << 8) + color.g * 255;
            *pixel = (*pixel << 8) + color.b * 255;
            // printf("%u\n", *pixel);
            j++;
        }
        i++;
    }
}

void
    fill_image(t_info *info)
{
    t_ray           ray;
    int             x;
    int             y;

    x = 0;
    intersect_arr_init();
    while (x < info->res->x + info->various.reduc)
    {
        y = 0;
        while (y < 1 + info->various.reduc)
        {
            camera_ray_gen(&ray, info,
                x + info->various.reduc / 2, y + info->various.reduc / 2);
            find_closest(&ray, info, info->various.max_dist,
                info->various.max_bounce);
            chunk_fill(ray.color, info, x, y);
            y += info->various.reduc;
        }
        x += info->various.reduc;
    }
}
