/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 21:02:07 by user42            #+#    #+#             */
/*   Updated: 2020/11/17 09:56:58 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int
	intersect_disk(double *closest, t_ray *ray, t_cylinder *cylinder, t_vec3lf center)
{
	double      dist;
	t_vec3lf    hitpoint;
	t_vec3lf    disk_normal;

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

double
	intersect_cylinder_body(double *closest, t_ray *ray, t_cylinder *cylinder)
{
	double		quad[5];
	t_vec3lf	v_bottom_top;
	t_vec3lf	cross1;
	t_vec3lf	cross2;

	v_bottom_top = vecscale(cylinder->dir, cylinder->height);
	cross1 = veccross(vecnew(cylinder->pos, ray->pos), v_bottom_top);
	cross2 = veccross(ray->dir, v_bottom_top);
	quad[0] = vecdot(cross2, cross2);
	quad[1] = vecdot(cross2, cross1);
	quad[2] = vecdot(cross1, cross1)
		- (pow(cylinder->r, 2) * vecdot(v_bottom_top, v_bottom_top));
	quad[4] = pow(quad[1], 2) - (4 * quad[0] * quad[2]);
	if (quad[4] < 0)
		return (0);
	quad[2] = (quad[1] + sqrt(quad[4])) / (2 * quad[0]);
	quad[3] = (quad[1] - sqrt(quad[4])) / (2 * quad[0]);
	if (quad[3] > 0 && quad[2] > quad[3])
		quad[2] = quad[3];
	else if (quad[2] <= 0)
		return (0);
	if (*closest < quad[2] || quad[2] < EPSY)
		return (0);
	return (quad[2]);
}

int
	intersect_cylinder(double *closest, t_ray *ray, void *elem_detail)
{
	double      dist;
	double		ret;
	t_cylinder  *cylinder;
	t_vec3lf    hitpoint;
	t_vec3lf    proj;

	ret = 0;
	cylinder = elem_detail;
	if ((dist = intersect_cylinder_body(closest, ray, cylinder)))
	{
	printf("%lf\n", dist);
		hitpoint = vectranslat(ray->pos, ray->dir, dist);
		proj = vecsum(cylinder->pos, vecscale(cylinder->dir, vecdot(vecsub(ray->pos, cylinder->pos), cylinder->dir) / vecdot(cylinder->dir, cylinder->dir)));
		// print_vec3lf(proj);
		// printf("%lf\n", vecdot(vecsub(hitpoint, cylinder->pos), cylinder->dir));
		// if ((vecmag(vecsub(proj, cylinder->pos)) + vecmag(vecsub(proj, vectranslat(cylinder->pos, cylinder->dir, cylinder->height)))) <= cylinder->height)
		// {
			ray->b.pos = hitpoint;
			ray->b.n = vecnorm(vecnew(proj, hitpoint));
			// print_vec3lf(ray->b.n);
			if (vecdot(ray->b.n, ray->dir) < 0)
				ray->b.n = vecscale(ray->b.n, -1);
			ray->color = cylinder->color;
			*closest = dist;
			ret = 1;
		// }
	}
	if (intersect_disk(closest, ray, cylinder, cylinder->pos) ||
		intersect_disk(closest, ray, cylinder, vectranslat(cylinder->pos, cylinder->dir, cylinder->height)))
		ret = 1;
	return (ret);
}
