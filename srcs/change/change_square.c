/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_square.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 20:04:38 by user42            #+#    #+#             */
/*   Updated: 2020/11/23 02:18:25 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void
	change_square(void *elem_detail, int key, t_info *info)
{
	t_square	*square;

	square = elem_detail;
	if (!info->various.rot)
		square->pos = translate(square->pos, key, info);
	else
		square->dir =
			rotate(square->dir, info->cur_camera->elem_detail, key, info);
	square->height = var_scale(square->height, key);
}
