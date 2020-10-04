/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vecnorm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 18:48:30 by clkuznie          #+#    #+#             */
/*   Updated: 2020/09/30 19:07:36 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vec3lf
    vecnorm(const t_vec3lf *vector)
{
    t_vec3lf    normed;
    double      mag;

    mag = vecmag(vector);
    if (mag)
    {
        normed.x = vector->x / mag;
        normed.y = vector->y / mag;
        normed.z = vector->z / mag;
    }
    else
        normed = veczero();
    return (normed);
}
