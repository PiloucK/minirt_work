/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_parse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 20:08:05 by clkuznie          #+#    #+#             */
/*   Updated: 2020/10/06 13:25:25 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void
    cylinder_parse(char ***object_params, t_info *info)
{
    t_cylinder    *details;
    
    if (util_object_params_count(*object_params) != 6)
		err_print(3, info, "Wrong cylinder line format");
    if (!(details = malloc(sizeof(*details))))
        err_print(2, info, NULL);
    details->pos = position_parse((*object_params)[1], info);
    details->dir = vector_parse((*object_params)[2], info);
    details->diameter = double_parse_inrange((*object_params)[3], 0, 0, info);
    details->height = double_parse_inrange((*object_params)[4], 0, 0, info);
    details->color = color_parse((*object_params)[5], info);
    util_addelem(info, details, CY);
}
