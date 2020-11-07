/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vecscale.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 10:24:07 by clkuznie          #+#    #+#             */
/*   Updated: 2020/11/05 14:47:55 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vec3lf
    vecscale(t_vec3lf vector, const double i)
{
    vector.x *= i;
    vector.y *= i;
    vector.z *= i;
    return (vector);
}
