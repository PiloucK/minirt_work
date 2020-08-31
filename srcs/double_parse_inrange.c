/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_parse_inrange.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 19:39:32 by clkuznie          #+#    #+#             */
/*   Updated: 2020/08/31 20:22:08 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double
    double_parse_inrange(const char *s, double min_range, double max_range)
{
    double  d;

    d = strtod(s);
    if (d < min_range || d > max_range)
        errprint(3, info, "Wrong value in line (too big or too small)");
    return (d);
}
