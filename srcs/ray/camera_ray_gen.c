/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_ray_gen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 18:44:24 by clkuznie          #+#    #+#             */
/*   Updated: 2020/11/07 17:07:15 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void
    camera_ray_gen(t_ray *ray, t_info *info, double x, double y)
{
    // t_vec3lf    upguide;
    // t_vec3lf    v_up;
    // t_vec3lf    v_right;
    
    if (!info->cur_camera)
        err_print(4, info, "No camera found");
    ray->pos = info->cur_camera->pos;
    ray->dir = info->cur_camera->dir;
    
    // upguide = vecnewvalues(0, 0, 1);
    // v_right = vecnorm(veccross(ray->dir, upguide));
    // v_right.y = vecis(v_right, 0, 0, 0)
    //     + v_right.y * !vecis(v_right, 0, 0, 0);
    // v_up = vecnorm(veccross(v_right, ray->dir));
    // ray->dir = vecsum(ray->dir,
    //     vecscale(v_right,
    //         info->cur_camera->w * (1 - ((i + 0.5) * 2 / info->res->x))));
    // ray->dir = vecsum(ray->dir,
    //     vecscale(v_up,
    //         (info->cur_camera->w / (info->res->x / info->res->y))
    //         * (1 - ((j + 0.5) * 2 / info->res->y))));
            
    ray->dir = vecsum(ray->dir,
        vecscale(info->cur_camera->v_right,
            info->cur_camera->w * (1 - ((x + 0.5) * 2 / info->res->x))));
    ray->dir = vecsum(ray->dir,
        vecscale(info->cur_camera->v_up,
            (info->cur_camera->w / (info->res->x / info->res->y))
            * (1 - ((y + 0.5) * 2 / info->res->y))));
    ray->dir = vecnorm(ray->dir);
}
