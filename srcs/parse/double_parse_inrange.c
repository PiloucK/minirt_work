/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_parse_inrange.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 19:39:32 by clkuznie          #+#    #+#             */
/*   Updated: 2020/11/23 01:59:13 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double
	double_parse_inrange(char *value,
		double min_range, double max_range, t_info *info)
{
	double	d;
	char	*c;

	d = strtod(value, &c);
	if (min_range || max_range)
	{
		if (d < min_range || d > max_range)
			err_print(3, info, "Wrong value in line (too big or too small)");
	}
	if (*c)
		err_print(3, info, "Decimal value is needed");
	return (d);
}
