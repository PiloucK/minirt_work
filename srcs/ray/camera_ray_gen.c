/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_ray_gen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 18:44:24 by clkuznie          #+#    #+#             */
/*   Updated: 2020/10/14 15:30:42 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void
    camera_ray_gen(t_ray *ray, t_info *info, int i, int j)
{
    double  x;
    double  y;
    double  aspect_ratio;
    
    (void)info;
    if (!info->cur_camera)
        err_print(4, info, "No camera found");
    ray->pos = info->cur_camera->pos;
    aspect_ratio = info->res->x / info->res->y;
    (void)x;
    (void)y;
    (void)aspect_ratio;
    x = i / info->res->x;
    y = j / info->res->y;
    ray->pos.x = i;
    ray->pos.y = j;
    ray->dir = info->cur_camera->dir;
    ray->color = info->ambiant->color;
}
