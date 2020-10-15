/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_sphere.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 08:26:07 by clkuznie          #+#    #+#             */
/*   Updated: 2020/10/15 18:58:25 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double
    intersect_sphere(double *closest, t_ray *ray, void *elem_detail)
{
    t_sphere    *sphere;
    t_vec3lf    v_origin_center;
    double      dist_origin_proj;
    double      dist_ray_center;
    double      dist_origin_center;
    double      dist_proj_intersection;

    (void)dist_proj_intersection;
    sphere = elem_detail;
    if (!sphere)
        return (0);
    v_origin_center = vecnew(ray->pos, sphere->pos);
    dist_ray_center = vecprod(
        v_origin_center, ray->dir, vecangle(v_origin_center, ray->dir));
    if (dist_ray_center > sphere->diameter)
        return (0);
    dist_origin_proj = vecdotprod(v_origin_center, ray->dir);
    dist_origin_center = vecmag(v_origin_center);
    // if (dist_origin_center)
        dist_origin_center = dist_origin_proj +
            sqrt(sphere->diameter * sphere->diameter
            - dist_ray_center * dist_ray_center);
    // else
    //     dist_origin_center = sphere->diameter;
    if ((dist_origin_center > 0.1f) && (dist_origin_center < *closest))
    {
        ray->color = sphere->color;
        *closest = dist_origin_center;
    }
// printf("%lf\n", dist_origin_center + 2 * util_absvalue(dist_origin_proj));
// dist_origin_center -= sqrt(sphere->diameter * sphere->diameter
//     - dist_ray_center * dist_ray_center) * 2;
    else if ((dist_origin_center - sqrt(sphere->diameter * sphere->diameter
        - dist_ray_center * dist_ray_center) * 2 > 0.1f) && (dist_origin_center - sqrt(sphere->diameter * sphere->diameter
        - dist_ray_center * dist_ray_center) * 2 < *closest))
    {
        ray->color = sphere->color;
        *closest = dist_origin_center - sqrt(sphere->diameter * sphere->diameter
            - dist_ray_center * dist_ray_center) * 2;
    }
    else
        return (0);
    return (1);
}
