/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vecnewvalues.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 09:44:44 by clkuznie          #+#    #+#             */
/*   Updated: 2020/11/23 02:06:34 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vec3lf
	vecnewvalues(const double x, const double y, const double z)
{
	t_vec3lf	vector;

	vector.x = x;
	vector.y = y;
	vector.z = z;
	return (vector);
}
