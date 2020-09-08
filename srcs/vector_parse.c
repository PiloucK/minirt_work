/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 21:09:54 by clkuznie          #+#    #+#             */
/*   Updated: 2020/09/08 21:38:42 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vect
	vector_parse(char *object_param, t_info *info)
{
	char	**values;
	t_vect  vectors;

	values = ft_split(object_param, ',');
	if (!values)
		err_print(2, info, NULL);
	if (util_object_params_count(values) != 3)
		err_print(3, info, "Wrong vector values format");
	vectors.xdir = double_parse_inrange(values[0], -1.0, 1.0, info);
	vectors.ydir = double_parse_inrange(values[1], -1.0, 1.0, info);
	vectors.zdir = double_parse_inrange(values[2], -1.0, 1.0, info);
	// ndim_arrfree(values, 2);
	return (vectors);
}
