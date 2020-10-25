/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_ray_gen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 18:44:24 by clkuznie          #+#    #+#             */
/*   Updated: 2020/10/25 17:42:15 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void
    camera_ray_gen(t_ray *ray, t_info *info, double i, double j)
{
    double  aspect_ratio;
    double  h;
    double  w;
    t_vec3lf    v_right;
    t_vec3lf    upguide;
    t_vec3lf    v_up;

    if (!info->cur_camera)
        err_print(4, info, "No camera found");
    upguide = vecnewvalues(0, 0, 1);
    ray->pos = info->cur_camera->pos;
    aspect_ratio = info->res->x / info->res->y;
    w = tan(info->cur_camera->fov / 2 * (PI / 180));
    h = w / aspect_ratio;
    ray->dir = info->cur_camera->dir;
    v_right = vecnorm(veccross(ray->dir, upguide));
    v_right.y = -1.0 * vecis(v_right, 0, 0, 0) + v_right.y * !vecis(v_right, 0, 0, 0);
    v_up = vecnorm(veccross(v_right, ray->dir));
    w *= i * 2 / info->res->x - 1;
    h *= j * 2 / info->res->y - 1;
    v_up = vecscale(v_up, -h);
    v_right = vecscale(v_right, -w);
    ray->dir = vecsum(ray->dir, v_right);
    ray->dir = vecsum(ray->dir, v_up);
    ray->dir = vecnorm(ray->dir);
}
