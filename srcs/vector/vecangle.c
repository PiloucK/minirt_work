/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vecangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 19:53:44 by clkuznie          #+#    #+#             */
/*   Updated: 2020/09/30 19:58:00 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

double
    vecangle(const t_vec3lf *a, const t_vec3lf *b)
{
    return (
        acos(
            vecdotprod(a, b) / (vecmag(a) * vecmag(b))
        )
    );
}
