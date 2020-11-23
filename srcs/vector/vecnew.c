/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vecnew.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 18:13:43 by clkuznie          #+#    #+#             */
/*   Updated: 2020/11/23 02:06:27 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vec3lf
	vecnew(const t_vec3lf origin, const t_vec3lf dest)
{
	t_vec3lf	vector;

	vector.x = dest.x - origin.x;
	vector.y = dest.y - origin.y;
	vector.z = dest.z - origin.z;
	return (vector);
}
