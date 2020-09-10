/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 19:38:17 by clkuznie          #+#    #+#             */
/*   Updated: 2020/09/10 19:42:41 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void
    sphere_parse(char ***object_params, t_info *info)
{
    t_sphere    *details;
    
    if (util_object_params_count(*object_params) != 4)
		err_print(3, info, "Wrong sphere line format");
    if (!(details = malloc(sizeof(*details))))
        err_print(2, info, NULL);
    details->pos = position_parse((*object_params)[1], info);
    details->diameter = double_parse_inrange((*object_params)[2], 0, 0, info);
    details->color = color_parse((*object_params)[3], info);
    util_addelem(info, details, SP);
}
