/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_setup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 21:13:28 by user42            #+#    #+#             */
/*   Updated: 2020/11/12 15:46:20 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void
    movement_arr_init()
{
    int     i;

    i = 0;
    while (i < ARR_SIZE)
        g_movement_arr[i++] = move_nothing;
    // g_movement_arr[CY] = move_cylinder;
    // g_movement_arr[PL] = move_plane;
    // g_movement_arr[SP] = move_sphere;
    // g_movement_arr[SQ] = move_square;
    // g_movement_arr[TR] = move_triangle;
    // g_movement_arr[C] = move_camera;
    // g_movement_arr[L] = move_light;
}
