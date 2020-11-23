/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vecprod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 19:11:20 by clkuznie          #+#    #+#             */
/*   Updated: 2020/11/23 02:06:51 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

double
	vecprod(const t_vec3lf a, const t_vec3lf b, const double angle)
{
	return (vecmag(a) * vecmag(b) * sin(angle));
}
