/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 21:02:07 by user42            #+#    #+#             */
/*   Updated: 2020/11/23 04:54:56 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int
	intersect_disk(double *closest, t_ray *ray, t_cylinder *cylinder,
		t_vec3lf center)
{
	double		dist;
	t_vec3lf	hitpoint;
	t_vec3lf	disk_normal;

	disk_normal = cylinder->dir;
	if (!(dist = plane_dist(*closest, ray, &disk_normal, center)))
		return (0);
	hitpoint = vectranslat(ray->pos, ray->dir, dist);
	if (vecmag(vecnew(hitpoint, center)) > cylinder->r)
		return (0);
	set_bounce(ray, cylinder->color, hitpoint, disk_normal);
	*closest = dist;
	return (1);
}

static void
	limit_to_body_solutions(double quad[6], t_ray *ray, t_cylinder *cylinder)
{
	t_vec3lf	hit1;
	t_vec3lf	hit2;

	hit1 = vectranslat(ray->pos, ray->dir, quad[4]);
	hit2 = vectranslat(ray->pos, ray->dir, quad[5]);
	if (vecdot(vecsub(hit1, cylinder->pos), cylinder->dir) < 0 ||
		vecdot(vecsub(hit1, vectranslat(cylinder->pos, cylinder->dir,
			cylinder->height)), cylinder->dir) > 0)
		quad[4] = 0;
	if (vecdot(vecsub(hit2, cylinder->pos), cylinder->dir) < 0 ||
		vecdot(vecsub(hit2, vectranslat(cylinder->pos, cylinder->dir,
			cylinder->height)), cylinder->dir) > 0)
		quad[5] = 0;
}

static double
	intersect_cylinder_body(double *closest, t_ray *ray, t_cylinder *cylinder)
{
	double		quad[6];
	t_vec3lf	v_center_ray;
	t_vec3lf	hup;
	t_vec3lf	v_1;

	v_center_ray = vecsub(ray->pos, cylinder->pos);
	hup = vecsub(ray->dir,
		vecscale(cylinder->dir, vecdot(ray->dir, cylinder->dir)));
	quad[0] = vecdot(hup, hup);
	v_1 = vecsub(v_center_ray,
		vecscale(cylinder->dir, vecdot(v_center_ray, cylinder->dir)));
	quad[1] = 2 * vecdot(hup, v_1);
	quad[2] = vecdot(v_1, v_1) - pow(cylinder->r, 2);
	if ((quad[3] = (pow(quad[1], 2) - (4 * quad[0] * quad[2]))) < 0)
		return (0);
	quad[4] = ((-quad[1]) + sqrt(quad[3])) / (2 * quad[0]);
	quad[5] = ((-quad[1]) - sqrt(quad[3])) / (2 * quad[0]);
	limit_to_body_solutions(quad, ray, cylinder);
	if (quad[5] > EPSY && (quad[5] < quad[4] || quad[4] < EPSY))
		quad[4] = quad[5];
	if (quad[4] > *closest || quad[4] < EPSY)
		return (0);
	ray->b.pos = vectranslat(ray->pos, ray->dir, quad[4]);
	return (quad[4]);
}

int
	intersect_cylinder(double *closest, t_ray *ray, void *elem_detail)
{
	double		dist;
	double		ret;
	t_cylinder	*cylinder;

	ret = 0;
	cylinder = elem_detail;
	if ((dist = intersect_cylinder_body(closest, ray, cylinder)))
	{
		ray->b.n = vecnorm(vecnew(vectranslat(cylinder->pos, cylinder->dir,
		vecdot(vecnew(cylinder->pos, ray->b.pos), cylinder->dir)),
			ray->b.pos));
		if (vecdot(ray->b.n, ray->dir) > 0)
			ray->b.n = vecscale(ray->b.n, -1);
		ray->color = cylinder->color;
		*closest = dist;
		ret = 1;
	}
	if (intersect_disk(closest, ray, cylinder, cylinder->pos))
		ret = 1;
	if (intersect_disk(closest, ray, cylinder,
		vectranslat(cylinder->pos, cylinder->dir, cylinder->height)))
		ret = 1;
	return (ret);
}
