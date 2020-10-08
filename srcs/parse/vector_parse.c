/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 21:09:54 by clkuznie          #+#    #+#             */
/*   Updated: 2020/10/06 10:52:51 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3lf
	vector_parse(char *object_param, t_info *info)
{
	char	**values;
	t_vec3lf  vectors;

	values = ft_split(object_param, ',');
	info->splited_value = &values;
	if (!values)
		err_print(2, info, NULL);
	if (util_object_params_count(values) != 3)
		err_print(3, info, "Wrong vector values format");
	vectors.x = double_parse_inrange(values[0], -1.0, 1.0, info);
	vectors.y = double_parse_inrange(values[1], -1.0, 1.0, info);
	vectors.z = double_parse_inrange(values[2], -1.0, 1.0, info);
	arrfree(&values);
	info->splited_value = NULL;
	return (vectors);
}
