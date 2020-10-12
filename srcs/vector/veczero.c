/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   veczero.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 19:04:26 by clkuznie          #+#    #+#             */
/*   Updated: 2020/09/30 19:07:05 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vec3lf
    veczero(void)
{
    t_vec3lf    zero;

    zero.x = 0;
    zero.y = 0;
    zero.z = 0;
    return (zero);
}