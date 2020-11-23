/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooked.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 22:27:30 by user42            #+#    #+#             */
/*   Updated: 2020/11/23 02:28:46 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int
	mouse_hooked(int button, int x, int y, void *arg)
{
	t_info		*info;
	t_ray		ray;

	info = arg;
	if (button == 1)
	{
		camera_ray_gen(&ray, info, x, y);
		info->cur_object = find_closest(&ray, info, info->various.max_dist,
			info->various.max_bounce);
		if (!info->cur_object)
			info->cur_object = info->cur_camera;
	}
	else if (button == 2 || button == 3)
		info->cur_object = info->cur_camera;
	return (0);
}
