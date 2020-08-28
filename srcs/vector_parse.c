/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 21:09:54 by clkuznie          #+#    #+#             */
/*   Updated: 2020/08/28 21:41:46 by clkuznie         ###   ########.fr       */
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
		err_print(3, info, "Wrong vector line format");
	vectors.xdir = double_parse(values[0]);
	vectors.ydir = double_parse(values[1]);
	vectors.zdir = double_parse(values[2]);
	ndim_arrfree(values, 2);
	return (vectors);
}
