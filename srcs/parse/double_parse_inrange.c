/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_parse_inrange.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 19:39:32 by clkuznie          #+#    #+#             */
/*   Updated: 2020/09/10 19:26:49 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double
    double_parse_inrange(char *value,
        double min_range, double max_range, t_info *info)
{
    double  d;
    char    *c;

    d = strtod(value, &c);
ft_printf("____________________%c_\n", *(c));
    if (min_range && max_range)
    {
        if (d < min_range || d > max_range)
            err_print(3, info, "Wrong value in line (too big or too small)");
    }
    if (*c)
        err_print(3, info, "Wrong float number format");
    return (d);
}