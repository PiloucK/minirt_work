/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vecdotprod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 19:43:11 by clkuznie          #+#    #+#             */
/*   Updated: 2020/10/09 09:30:42 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

double
    vecdotprod(const t_vec3lf a, const t_vec3lf b)
{
    return (a.x * b.x + a.y * b.y + a.z * b.z);
}
