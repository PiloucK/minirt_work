/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooked.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 19:46:51 by user42            #+#    #+#             */
/*   Updated: 2020/11/23 08:51:09 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		key_hooked(int key, void *arg)
{
	t_info		*info;

	info = arg;
printf("%d\n", key);
	if (key == 65363)
		camera_switch(arg);
	else if (key == 65361)
		light_switch(arg);
	else if (key == 65293)
		info->various.rot = 0;
	else if (key == 114)
		info->various.rot = !info->various.rot;
	else if (key == 32)
		info->various.reduc = -1;
	else if (key == 65307)
		err_close(info);
	else if (info->various.rot == 2)
		(*g_change_arr[L])(info->cur_object->elem_detail, key, arg);
	else
		(*g_change_arr[info->cur_object->id])(info->cur_object->elem_detail,
			key, arg);
	fill_image(arg);
	mlx_put_image_to_window(info->mlx, info->win, info->image.img, 0, 0);
	info->various.reduc = ((info->res->x * info->res->y) > 10000 ? REDUC : 1);
	return (0);
}
