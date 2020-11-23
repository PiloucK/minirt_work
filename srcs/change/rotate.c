/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 20:15:43 by user42            #+#    #+#             */
/*   Updated: 2020/11/23 08:52:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3lf
	do_rotation(t_vec3lf v, t_vec3lf n, double ratio)
{
	t_vec3lf	proj_vector;
	t_vec3lf	err_vector;

	proj_vector = vecscale(n, vecdot(v, n));
	err_vector = vecsub(v, proj_vector);
	v = vecnorm(vecsum(proj_vector, vecsum(vecscale(err_vector, cos(ratio)),
		vecscale(veccross(v, n), sin(ratio)))));
	return (v);
}

t_vec3lf
	select_axis(t_camera *camera, int key, double *ratio, t_info *info)
{
	*ratio = ((key == 119 * 1.0) * (2.0 * PI - info->various.rot_speed))
	+ ((key == 115 * 1.0) * info->various.rot_speed)
	+ ((key == 97 * 1.0) * (2.0 * PI - info->various.rot_speed))
	+ ((key == 100 * 1.0) * info->various.rot_speed)
	+ ((key == 65507 * 1.0) * (2.0 * PI - info->various.rot_speed))
	+ ((key == 65505 * 1.0) * info->various.rot_speed);
	if (key == 119 || key == 115)
		return (camera->v_right);
	if (key == 97 || key == 100)
		return (camera->v_up);
	return (camera->dir);
}

t_vec3lf
	rotate(t_vec3lf v, t_camera *camera, int key, t_info *info)
{
	double		ratio;
	t_vec3lf	rotation_axis;

	ratio = 0.0;
	rotation_axis = select_axis(camera, key, &ratio, info);
	return (do_rotation(v, rotation_axis, ratio));
}
