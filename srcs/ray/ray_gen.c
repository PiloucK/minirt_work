/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_gen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 18:44:24 by clkuznie          #+#    #+#             */
/*   Updated: 2020/10/06 10:52:51 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void
    ray_gen(t_ray *ray, t_info *info)
{
    (void)info;
    if (!info->cur_camera)
        err_print(4, info, "No camera found");
    // ray->pos.z = -1000.0;
    // ray->dir.x = 0.0;
    // ray->dir.y = 0.0;
    // ray->dir.z = 1.0;;
    // ray->pos.z = info->cur_cameras->;
    ray->dir.x = 0.0;
    ray->dir.y = 0.0;
    ray->dir.z = 1.0;;
}
