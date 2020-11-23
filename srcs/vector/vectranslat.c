/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectranslat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 08:28:09 by clkuznie          #+#    #+#             */
/*   Updated: 2020/11/23 02:09:05 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vec3lf
	vectranslat(const t_vec3lf origin, const t_vec3lf direction,
	const double dist)
{
	t_vec3lf	vec;

	vec = vecnorm(direction);
	vec.x = origin.x + direction.x * dist;
	vec.y = origin.y + direction.y * dist;
	vec.z = origin.z + direction.z * dist;
	return (vec);
}
