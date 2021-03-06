/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vecangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 19:53:44 by clkuznie          #+#    #+#             */
/*   Updated: 2020/11/23 02:09:37 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

double
	vecangle(const t_vec3lf a, const t_vec3lf b)
{
	return (acos(vecdot(a, b) / (vecmag(a) * vecmag(b))));
}
