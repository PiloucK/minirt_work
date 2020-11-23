/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_cone.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 02:17:54 by user42            #+#    #+#             */
/*   Updated: 2020/11/23 08:32:53 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void
	change_cone(void *elem_detail, int key, t_info *info)
{
	t_cone	*cone;
	double	tmp_angle;

	cone = elem_detail;
	if (!info->various.rot)
		cone->apex = translate(cone->apex, key, info);
	else
		cone->dir =
			rotate(cone->dir, info->cur_camera->elem_detail, key, info);
	if ((tmp_angle = var_scale(cone->angle, key)) < (89 * (PI / 180)))
		cone->angle = tmp_angle;
}
