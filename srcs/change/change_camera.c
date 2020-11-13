/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_camera.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 14:12:20 by user42            #+#    #+#             */
/*   Updated: 2020/11/13 11:35:58 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void
    change_camera(void *elem_detail, int key, t_info *info)
{
    t_camera    *camera;

    camera = elem_detail;
    if (!info->various.rot)
        camera->pos = translate(camera->pos, key, info);
    else
    {
        if (key == 65505 || key == 65507)
        {
            camera->v_up = rotate(camera->v_up, camera, key, info);
            camera->v_right = rotate(camera->v_right, camera, key, info);
            camera->dir = vecnorm(veccross(camera->v_right, camera->v_up));
        }
        else
        {
            camera->dir = rotate(camera->dir, camera, key, info);
            camera->v_right = rotate(camera->v_right, camera, key, info);
            camera->v_up = vecnorm(veccross(camera->dir, camera->v_right));
        }
    }
    camera->fov = var_scale(camera->fov, key);
}
