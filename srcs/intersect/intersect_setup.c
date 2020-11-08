/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_setup.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 08:31:01 by clkuznie          #+#    #+#             */
/*   Updated: 2020/11/08 21:04:01 by user42           ###   ########.fr       */
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
    intersect_arr[PL] = intersect_plane;
    intersect_arr[TR] = intersect_triangle;
    intersect_arr[CY] = intersect_cylinder;
}
