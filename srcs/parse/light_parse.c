/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 18:22:51 by clkuznie          #+#    #+#             */
/*   Updated: 2020/11/23 01:57:26 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void
	light_parse(char ***object_params, t_info *info)
{
	t_light_list	*light;

	if (util_object_params_count(*object_params) != 4)
		err_print(3, info, "Wrong light line format");
	if (!(light = malloc(sizeof(*light))))
		err_print(2, info, NULL);
	light->pos = position_parse((*object_params)[1], info);
	light->ratio = double_parse_inrange((*object_params)[2], 0.0, 1.0, info);
	light->color = color_parse((*object_params)[3], info);
	light->next_light = info->first_light;
	info->first_light = light;
	info->cur_light = light;
}
