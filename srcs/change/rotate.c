/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 20:15:43 by user42            #+#    #+#             */
/*   Updated: 2020/11/12 19:36:22 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3lf
    rotate(t_vec3lf v, t_camera *camera, int key, t_info *info)
{
    if (key == 44 || key == 111)
        v = vecnorm(vecsum(vecscale(v, cos(
            ((key == 44 * 1.0) * (2.0 * PI - info->various.rot_speed))
            + ((key == 111 * 1.0) * info->various.rot_speed))),
            vecscale(vecnorm(veccross(v, camera->v_right)), sin(
                ((key == 44 * 1.0) * (2.0 * PI - info->various.rot_speed))
                + ((key == 111 * 1.0) * info->various.rot_speed)))));
    else if (key == 97 || key == 101)
        v = vecnorm(vecsum(vecscale(v, cos(
            ((key == 97 * 1.0) * (2 * PI - info->various.rot_speed))
            + ((key == 101 * 1.0) * info->various.rot_speed))),
            vecscale(vecnorm(veccross(v, camera->v_up)), sin(
                ((key == 97 * 1.0) * (2 * PI - info->various.rot_speed))
                + ((key == 101 * 1.0) * info->various.rot_speed)))));
    else if (key == 65505 || key == 65507)
        v = vecnorm(vecsum(vecscale(v, cos(
            ((key == 65507 * 1.0) * (2 * PI - info->various.rot_speed))
            + ((key == 65505 * 1.0) * info->various.rot_speed))),
            vecscale(vecnorm(veccross(v, camera->dir)), sin(
                ((key == 65507 * 1.0) * (2 * PI - info->various.rot_speed))
                + ((key == 65505 * 1.0) * info->various.rot_speed)))));
    return (v);
}
