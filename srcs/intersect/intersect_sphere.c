/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_sphere.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 08:26:07 by clkuznie          #+#    #+#             */
/*   Updated: 2020/11/19 11:16:42 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int
	intersect_sphere(double *closest, t_ray *ray, void *elem_detail)
{
	t_sphere	*sphere;
	double		quad[5];
	t_vec3lf	hit;

	sphere = elem_detail;
	quad[0] = 2 * vecdot(ray->dir, vecnew(sphere->pos, ray->pos));
	quad[1] = vecdot(vecnew(sphere->pos, ray->pos),
		vecnew(sphere->pos, ray->pos)) - pow(sphere->r, 2);
	if ((quad[4] = (pow(quad[0], 2) - (4 * quad[1]))) < 0)
		return (0);
	quad[2] = 0.5 * ((-quad[0]) + sqrt(quad[4]));
	quad[3] = 0.5 * ((-quad[0]) - sqrt(quad[4]));
	if (quad[3] > 0 && quad[2] > quad[3])
		quad[2] = quad[3];
	else if (quad[2] <= 0)
		return (0);
	if (*closest < quad[2] || quad[2] < EPSY)
		return (0);
	hit = vectranslat(ray->pos, ray->dir, quad[2]);
	ray->b.pos = hit;
	ray->color = sphere->color;
	*closest = quad[2];
	if (vecdot(ray->dir, (ray->b.n = vecnorm(vecnew(sphere->pos, hit)))) > 0)
		ray->b.n = vecscale(ray->b.n, -1);
	return (1);
}
