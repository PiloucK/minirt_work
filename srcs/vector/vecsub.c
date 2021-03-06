/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vecsub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 12:02:34 by clkuznie          #+#    #+#             */
/*   Updated: 2020/11/23 02:07:03 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vec3lf
	vecsub(const t_vec3lf a, const t_vec3lf b)
{
	t_vec3lf	sub;

	sub.x = a.x - b.x;
	sub.y = a.y - b.y;
	sub.z = a.z - b.z;
	return (sub);
}
