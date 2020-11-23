/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 17:48:15 by user42            #+#    #+#             */
/*   Updated: 2020/11/23 04:45:43 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static double
	best_quad_solution(double *closest, double a, double b, double c)
{
	double		discrim;
	double		sol1;
	double		sol2;

	if ((discrim = (pow(b, 2) - (4 * a * c))) < 0)
		return (0);
	sol1 = ((-b) + sqrt(discrim)) / (2 * a);
	sol2 = ((-b) - sqrt(discrim)) / (2 * a);
	if (sol2 > EPSY && (sol2 < sol1 || sol1 < EPSY))
		sol1 = sol2;
	if (*closest < sol1 || sol1 < EPSY)
		return (0);
	return (sol1);
}

static double
	intersect_cone_body(double *closest, t_ray *ray, t_cone *cone)
{
	double		quad[6];
	t_vec3lf	v_apex_ray;
	t_vec3lf	hup;
	t_vec3lf	v_1;

	v_apex_ray = vecsub(ray->pos, cone->apex);
	hup = vecsub(ray->dir,
		vecscale(cone->dir, vecdot(ray->dir, cone->dir)));
	quad[0] = pow(cos(cone->angle), 2) * vecdot(hup, hup)
		- pow(sin(cone->angle), 2) * pow(vecdot(ray->dir, cone->dir), 2);
	v_1 = vecsub(v_apex_ray,
		vecscale(cone->dir, vecdot(v_apex_ray, cone->dir)));
	quad[1] = 2 * pow(cos(cone->angle), 2) * vecdot(v_1, hup)
		- 2 * pow(sin(cone->angle), 2) * vecdot(ray->dir, cone->dir)
		* vecdot(v_apex_ray, cone->dir);
	quad[2] = pow(cos(cone->angle), 2) * vecdot(v_1, v_1)
		- pow(sin(cone->angle), 2) * pow(vecdot(v_apex_ray, cone->dir), 2);
	return (best_quad_solution(closest, quad[0], quad[1], quad[2]));
}

int
	intersect_cone(double *closest, t_ray *ray, void *elem_detail)
{
	double		dist;
	t_cone		*cone;
	t_vec3lf	hitpoint;
	t_vec3lf	proj;

	cone = elem_detail;
	if ((dist = intersect_cone_body(closest, ray, cone)))
	{
		hitpoint = vectranslat(ray->pos, ray->dir, dist);
		if (vecdot(vecnew(cone->apex, hitpoint), cone->dir) < 0)
			proj = vectranslat(cone->apex, cone->dir,
				-vecmag(vecnew(cone->apex, hitpoint)) / cos(cone->angle));
		else
			proj = vectranslat(cone->apex, cone->dir,
				vecmag(vecnew(cone->apex, hitpoint)) / cos(cone->angle));
		ray->b.pos = hitpoint;
		ray->b.n = vecnorm(vecnew(proj, hitpoint));
		if (vecdot(ray->b.n, ray->dir) > 0)
			ray->b.n = vecscale(ray->b.n, -1);
		ray->color = cone->color;
		*closest = dist;
		return (1);
	}
	return (0);
}
