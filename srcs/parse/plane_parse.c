/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 20:00:46 by clkuznie          #+#    #+#             */
/*   Updated: 2020/11/23 02:01:24 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void
	plane_parse(char ***object_params, t_info *info)
{
	t_plane		*details;

	if (util_object_params_count(*object_params) != 4)
		err_print(3, info, "Wrong plane line format");
	if (!(details = malloc(sizeof(*details))))
		err_print(2, info, NULL);
	details->pos = position_parse((*object_params)[1], info);
	details->dir = vector_parse((*object_params)[2], info);
	details->color = color_parse((*object_params)[3], info);
	util_addelem(info, details, PL);
}
