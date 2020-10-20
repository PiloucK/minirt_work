/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_ray_gen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 18:44:24 by clkuznie          #+#    #+#             */
/*   Updated: 2020/10/20 17:53:16 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void
    camera_ray_gen(t_ray *ray, t_info *info, int i, int j)
{
    double  x;
    double  y;
    double  aspect_ratio;
    double  h;
    double  w;

    if (!info->cur_camera)
        err_print(4, info, "No camera found");
    ray->pos = info->cur_camera->pos;
    aspect_ratio = info->res->x / info->res->y;
    x = i * 2 / info->res->x - 1;
    y = j * 2 / info->res->y - 1;
    w = atan(info->cur_camera->fov / 2);
    h = w / aspect_ratio;
    ray->dir = info->cur_camera->dir;
    ray->color = info->ambiant->color;
}
