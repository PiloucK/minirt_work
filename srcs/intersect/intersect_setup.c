/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_setup.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 08:31:01 by clkuznie          #+#    #+#             */
/*   Updated: 2020/11/01 17:25:25 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void
    intersect_arr_init()
{
    int             i;
    
    i = 0;
    while (i < 256)
        intersect_arr[i++] = intersect_ntdh;
    intersect_arr[SP] = intersect_sphere;
    // intersect_arr[PL] = intersect_plane;
}
