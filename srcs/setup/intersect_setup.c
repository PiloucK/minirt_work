/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_setup.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 08:31:01 by clkuznie          #+#    #+#             */
/*   Updated: 2020/11/12 15:46:20 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void
    intersect_arr_init()
{
    int     i;

    i = 0;
    while (i < ARR_SIZE)
        g_intersect_arr[i++] = intersect_nothing;
    g_intersect_arr[CY] = intersect_cylinder;
    g_intersect_arr[PL] = intersect_plane;
    g_intersect_arr[SP] = intersect_sphere;
    g_intersect_arr[SQ] = intersect_square;
    g_intersect_arr[TR] = intersect_triangle;
}
