/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 21:38:20 by clkuznie          #+#    #+#             */
/*   Updated: 2020/10/15 10:56:41 by clkuznie         ###   ########.fr       */
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
    details->dir = vecnorm(details->dir);
    details->fov = double_parse_inrange((*object_params)[3], 0, 180, info);
    info->cur_camera = details;
    util_addelem(info, details, C);
}
