/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle_parse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 20:12:01 by clkuznie          #+#    #+#             */
/*   Updated: 2020/10/09 12:39:55 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void
    triangle_parse(char ***object_params, t_info *info)
{
    t_triangle    *details;
    
    if (util_object_params_count(*object_params) != 5)
		err_print(3, info, "Wrong triangle line format");
    if (!(details = malloc(sizeof(*details))))
        err_print(2, info, NULL);
    details->a = position_parse((*object_params)[1], info);
    details->b = position_parse((*object_params)[2], info);
    details->c = position_parse((*object_params)[3], info);
    details->color = color_parse((*object_params)[4], info);
    util_addelem(info, details, TR);
}
