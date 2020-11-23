/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 20:15:35 by user42            #+#    #+#             */
/*   Updated: 2020/11/23 02:16:55 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3lf
	translate(t_vec3lf pos, int key, t_info *info)
{
	t_camera	*cur_camera;

	cur_camera = info->cur_camera->elem_detail;
	if (key == 44 || key == 111)
		pos = vectranslat(pos, cur_camera->dir,
			(key == 44 * info->various.tran_speed)
			+ -(key == 111 * info->various.tran_speed));
	else if (key == 97 || key == 101)
		pos = vectranslat(pos, cur_camera->v_right,
			(key == 97 * info->various.tran_speed)
			+ -(key == 101 * info->various.tran_speed));
	else if (key == 65505 || key == 65507)
		pos = vectranslat(pos, cur_camera->v_up,
			(key == 65505 * info->various.tran_speed)
			+ -(key == 65507 * info->various.tran_speed));
	return (pos);
}
