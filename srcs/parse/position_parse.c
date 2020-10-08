/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_parse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 20:15:23 by clkuznie          #+#    #+#             */
/*   Updated: 2020/10/06 10:51:13 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3lf
    position_parse(char *object_param, t_info *info)
{
    char	**values;
	t_vec3lf  positions;

	values = ft_split(object_param, ',');
	info->splited_value = &values;
	if (!values)
		err_print(2, info, NULL);
	if (util_object_params_count(values) != 3)
		err_print(3, info, "Wrong position values format");
	positions.x = double_parse_inrange(values[0], 0, 0, info);
	positions.y = double_parse_inrange(values[1], 0, 0, info);
	positions.z = double_parse_inrange(values[2], 0, 0, info);
	arrfree(&values);
	info->splited_value = NULL;
	return (positions);
}
