/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 21:09:54 by clkuznie          #+#    #+#             */
/*   Updated: 2020/11/09 21:18:49 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3lf
	vector_parse(char *object_param, t_info *info)
{
	char	**values;
	t_vec3lf  vector;

	values = ft_split(object_param, ',');
	info->splited_value = &values;
	if (!values)
		err_print(2, info, NULL);
	if (util_object_params_count(values) != 3)
		err_print(3, info, "Wrong vector values format");
	vector.x = double_parse_inrange(values[0], -1.0, 1.0, info);
	vector.y = double_parse_inrange(values[1], -1.0, 1.0, info);
	vector.z = double_parse_inrange(values[2], -1.0, 1.0, info);
	arrfree(&values);
	info->splited_value = NULL;
	vector = vecnorm(vector);
	if (vecis(vector, 0, 0, 0))
		err_print(3, info, "No direction value");
	return (vector);
}
