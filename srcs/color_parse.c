/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 17:08:10 by clkuznie          #+#    #+#             */
/*   Updated: 2020/09/09 17:25:10 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color
    color_parse(char *object_param, t_info *info)
{
    char	**values;
	t_color  colors;

	values = ft_split(object_param, ',');
	info->splited_value = &values;
	if (!values)
		err_print(2, info, NULL);
	if (util_object_params_count(values) != 3)
		err_print(3, info, "Wrong color values format");
	colors.r = double_parse_inrange(values[0], 0.0, 255.0, info);
	colors.g = double_parse_inrange(values[1], 0.0, 255.0, info);
	colors.b = double_parse_inrange(values[2], 0.0, 255.0, info);
	arrfree(&values);
	return (colors);
}