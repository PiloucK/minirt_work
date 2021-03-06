/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redirect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 15:47:59 by clkuznie          #+#    #+#             */
/*   Updated: 2020/11/23 01:54:11 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void
	uniforme(char *line)
{
	while (*line)
	{
		if (ft_iswspace(*line))
			*line = ' ';
		line++;
	}
}

static void
	parse_switch(char ***object_params, t_info *info)
{
	if (!ft_memcmp((*object_params)[0], "R", 2))
		resolution_parse(object_params, info);
	else if (!ft_memcmp((*object_params)[0], "A", 2))
		ambiant_parse(object_params, info);
	else if (!ft_memcmp((*object_params)[0], "c", 2))
		camera_parse(object_params, info);
	else if (!ft_memcmp((*object_params)[0], "l", 2))
		light_parse(object_params, info);
	else if (!ft_memcmp((*object_params)[0], "sp", 3))
		sphere_parse(object_params, info);
	else if (!ft_memcmp((*object_params)[0], "pl", 3))
		plane_parse(object_params, info);
	else if (!ft_memcmp((*object_params)[0], "sq", 3))
		square_parse(object_params, info);
	else if (!ft_memcmp((*object_params)[0], "cy", 3))
		cylinder_parse(object_params, info);
	else if (!ft_memcmp((*object_params)[0], "co", 3))
		cone_parse(object_params, info);
	else if (!ft_memcmp((*object_params)[0], "tr", 3))
		triangle_parse(object_params, info);
	else
		err_print(3, info, "RAFL Unknown object type");
}

void
	parse_redirect(t_info *info)
{
	char	**object_params;

	uniforme(info->last_read_str);
	object_params = ft_split(info->last_read_str, ' ');
	info->splited_line = &object_params;
	if (!object_params)
		err_print(2, info, NULL);
	if (object_params[0])
		parse_switch(&object_params, info);
	arrfree(&object_params);
	info->splited_line = NULL;
}
