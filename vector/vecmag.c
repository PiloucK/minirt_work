/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vecmag.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 18:41:39 by clkuznie          #+#    #+#             */
/*   Updated: 2020/09/30 19:02:52 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

double
    vecmag(const t_vec3lf *vector)
{
    return (sqrt(
        vector->x * vector->x
        + vector->y * vector->y
        + vector->z * vector->z
        ));
}
