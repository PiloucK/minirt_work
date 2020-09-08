/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 21:38:20 by clkuznie          #+#    #+#             */
/*   Updated: 2020/09/08 21:36:37 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void
    camera_parse(char **object_params, t_info *info)
{
    t_camera    *details;
    
    if (util_object_params_count(object_params) != 4)
		err_print(3, info, "Wrong camera line format");
    if (!(details = malloc(sizeof(*details))))
        err_print(2, info, NULL);
    // details->pos = double_parse_inrange(object_params[1], 0, 0, info);
    details->dir_vect = vector_parse(object_params[2], info);
    details->fov = ft_atoi(object_params[3]);
    if (details->fov < 0 || details->fov > 180)
        err_print(3, info, "Impossible fov value");
    util_addelem(info, details, C);
}
