/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 17:49:11 by user42            #+#    #+#             */
/*   Updated: 2020/11/23 08:07:31 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void
	cone_parse(char ***object_params, t_info *info)
{
	t_cone		*details;

	if (util_object_params_count(*object_params) != 5)
		err_print(3, info, "Wrong cone line format");
	if (!(details = malloc(sizeof(*details))))
		err_print(2, info, NULL);
	details->apex = position_parse((*object_params)[1], info);
	details->dir = vector_parse((*object_params)[2], info);
	details->angle = double_parse_inrange((*object_params)[3], 0, 180, info)
		/ 2 * (PI / 180);
	if (!details->angle || double_parse_inrange((*object_params)[3], 0, 180,
		info) == 180)
		err_print(3, info, "Can't use angle value of 0 or 180");
	details->color = color_parse((*object_params)[4], info);
	util_addelem(info, details, CO);
}
