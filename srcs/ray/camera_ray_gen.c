/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_ray_gen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 18:44:24 by clkuznie          #+#    #+#             */
/*   Updated: 2020/10/09 23:31:21 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void
    camera_ray_gen(t_ray *ray, t_info *info, int i, int j)
{
    (void)info;
    if (!info->cur_camera)
        err_print(4, info, "No camera found");
    ray->pos = info->cur_camera->pos;
    ray->pos.x = i;
    ray->pos.y = j;
    ray->dir = info->cur_camera->dir;
    ray->color = 0;
}
