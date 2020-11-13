/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_ray_gen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 18:44:24 by clkuznie          #+#    #+#             */
/*   Updated: 2020/11/12 22:49:01 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void
    camera_ray_gen(t_ray *ray, t_info *info, double x, double y)
{
    t_camera    *cur_camera;
    
    cur_camera = info->cur_camera->elem_detail;
    if (!cur_camera)
        err_print(4, info, "No camera found");
    ray->pos = cur_camera->pos;
    ray->dir = vecsum(cur_camera->dir,
        vecscale(cur_camera->v_right,
            cur_camera->w * (1 - ((x + 0.5) * 2 / info->res->x))));
    ray->dir = vecsum(ray->dir,
        vecscale(cur_camera->v_up,
            (cur_camera->w * (info->res->y / info->res->x))
            * (1 - ((y + 0.5) * 2 / info->res->y))));
    ray->dir = vecnorm(ray->dir);
}
