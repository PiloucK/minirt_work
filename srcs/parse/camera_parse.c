/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 21:38:20 by clkuznie          #+#    #+#             */
/*   Updated: 2020/11/13 11:28:57 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void
    camera_parse(char ***object_params, t_info *info)
{
    t_camera    *details;
    
    if (util_object_params_count(*object_params) != 4)
		err_print(3, info, "Wrong camera line format");
    if (!(details = malloc(sizeof(*details))))
        err_print(2, info, NULL);
    details->pos = position_parse((*object_params)[1], info);
    details->dir = vector_parse((*object_params)[2], info);
    details->fov = double_parse_inrange((*object_params)[3], 0, 180, info);
    details->w = tan(details->fov / 2 * (PI / 180));
    details->upguide = vecnewvalues(0, 0, 1);
    details->v_right = vecnorm(veccross(details->dir, details->upguide));
    details->v_right.y = vecis(details->v_right, 0, 0, 0)
        + details->v_right.y * !vecis(details->v_right, 0, 0, 0);
    details->v_up = vecnorm(veccross(details->v_right, details->dir));
    details->v_right = vecscale(details->v_right, -1);
    util_addelem(info, details, C);
    info->cur_camera = info->first_elem;
    info->cur_object = info->first_elem;
}
