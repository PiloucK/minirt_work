/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vecis.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 15:50:36 by clkuznie          #+#    #+#             */
/*   Updated: 2020/11/23 02:05:54 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

int
	vecis(const t_vec3lf vector, const double x, const double y, const double z)
{
	return (!((vector.x != x) + (vector.y != y) + (vector.z != z)));
}
