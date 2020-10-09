/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vecprod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 19:11:20 by clkuznie          #+#    #+#             */
/*   Updated: 2020/10/09 11:20:39 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

double
    vecprod(const t_vec3lf a, const t_vec3lf b, const double angle)
{
    return (vecmag(a) * vecmag(b) * sin(angle));
}
