/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_setup.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 08:31:01 by clkuznie          #+#    #+#             */
/*   Updated: 2020/10/06 08:31:11 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void
    intersect_arr_init()
{
    int             i;
    
    i = 0;
    while (i < 256)
        intersect_arr[i++] = intersect_rafl;
    intersect_arr[SP] = intersect_sphere;
}
