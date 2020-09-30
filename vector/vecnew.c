/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vecnew.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 18:13:43 by clkuznie          #+#    #+#             */
/*   Updated: 2020/09/30 18:52:47 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vec3lf
    vecnew(const t_vec3lf *origin, const t_vec3lf *dest)
{
    t_vec3lf    vector;

    vector.x = sqrt(dest->x * dest->x - origin->x * origin->x);
    vector.y = sqrt(dest->y * dest->y - origin->y * origin->y);
    vector.z = sqrt(dest->z * dest->z - origin->z * origin->z);
    return (vector);
}
