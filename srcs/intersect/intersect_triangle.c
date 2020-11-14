/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_triangle.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 10:44:41 by user42            #+#    #+#             */
/*   Updated: 2020/11/14 14:45:33 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int
	intersect_triangle(double *closest, t_ray *ray, void *elem_detail)
{
	t_triangle	*tr;
	t_vec3lf	hitpoint;
	t_vec3lf	v_vert_hit;
	double		dist;
	double		in;

	tr = elem_detail;
	if (!(dist = plane_dist(*closest, ray, &(tr->normal), tr->a)))
		return (0);
	hitpoint = vectranslat(ray->pos, ray->dir, dist);
	v_vert_hit = vecnew(tr->a, hitpoint);
	in = 0;
	in += vecdot(tr->normal, veccross(vecnew(tr->a, tr->b), v_vert_hit)) > 0;
	v_vert_hit = vecnew(tr->b, hitpoint);
	in += vecdot(tr->normal, veccross(vecnew(tr->b, tr->c), v_vert_hit)) > 0;
	v_vert_hit = vecnew(tr->c, hitpoint);
	in += vecdot(tr->normal, veccross(vecnew(tr->c, tr->a), v_vert_hit)) > 0;
	if (in != 0 && in != 3)
		return (0);
	set_bounce(ray, tr->color, hitpoint, tr->normal);
	*closest = dist;
	return (1);
}
