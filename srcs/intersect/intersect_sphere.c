/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_sphere.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 08:26:07 by clkuznie          #+#    #+#             */
/*   Updated: 2020/10/14 15:31:28 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double
    intersect_sphere(double *closest, t_ray *ray, void *elem_detail)
{
    t_sphere    *sphere;
    t_vec3lf    v_origin_center;
    double      dist_origin_center_onray;
    double      dist_ray_center;
    double      tmp;

    sphere = elem_detail;
    if (!sphere)
        return (0);
    v_origin_center = vecnew(ray->pos, sphere->pos);
    dist_origin_center_onray = vecdotprod(v_origin_center, ray->dir);
    tmp = vecmag(v_origin_center);
    dist_ray_center = vecprod(
        v_origin_center, ray->dir, vecangle(v_origin_center, ray->dir));
    if (dist_ray_center > sphere->diameter)
        return (0);
    if (tmp)
        tmp = dist_origin_center_onray +
            sqrt(sphere->diameter * sphere->diameter
            - dist_ray_center * dist_ray_center);
    else
        tmp = sphere->diameter;
    if ((tmp > 0.1f) && (tmp < *closest))
    {
        ray->color = sphere->color;
        *closest = tmp;
    }
// printf("%lf\n", tmp + 2 * util_absvalue(dist_origin_center_onray));
    // tmp -= sqrt(sphere->diameter * sphere->diameter
    //     - dist_ray_center * dist_ray_center) * 2;
    else if ((tmp - sqrt(sphere->diameter * sphere->diameter
        - dist_ray_center * dist_ray_center) * 2 > 0.1f) && (tmp - sqrt(sphere->diameter * sphere->diameter
        - dist_ray_center * dist_ray_center) * 2 < *closest))
    {
        ray->color = sphere->color;
        *closest = tmp - sqrt(sphere->diameter * sphere->diameter
            - dist_ray_center * dist_ray_center) * 2;
    }
    else
        return (0);
    return (1);
}
