/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_setup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 21:13:28 by user42            #+#    #+#             */
/*   Updated: 2020/11/23 02:05:08 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void
	change_arr_init(void)
{
	int		i;

	i = 0;
	while (i < ARR_SIZE)
		g_change_arr[i++] = change_nothing;
	g_change_arr[C] = change_camera;
	g_change_arr[CO] = change_cone;
	g_change_arr[CY] = change_cylinder;
	g_change_arr[L] = change_light;
	g_change_arr[PL] = change_plane;
	g_change_arr[SP] = change_sphere;
	g_change_arr[SQ] = change_square;
	g_change_arr[TR] = change_triangle;
}
