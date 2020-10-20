/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_sphere.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 08:26:07 by clkuznie          #+#    #+#             */
/*   Updated: 2020/10/20 16:07:56 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double
    intersect_sphere(double *closest, t_ray *ray, void *elem_detail)
{
    t_sphere    *sphere;
    t_vec3lf    v_origin_center;
    double      dist_origin_proj;
    double      dist_proj_center;
    double      dist_origin_center;
    double      dist_proj_intersection;
    double      dist_origin_intersection;
    double      tmp;

    sphere = elem_detail;
    tmp = *closest;
    if (!sphere)
        return (0);
    v_origin_center = vecnew(ray->pos, sphere->pos);
    dist_proj_center = vecprod(
        v_origin_center, ray->dir, vecangle(v_origin_center, ray->dir));
    if (dist_proj_center > sphere->diameter)
        return (0);
    dist_origin_proj = vecdotprod(v_origin_center, ray->dir);
    dist_origin_center = vecmag(v_origin_center);
    if (dist_origin_proj <= 0)
    {
        if (dist_origin_center < sphere->diameter - 0.1)
        {
            dist_proj_intersection = sqrt(sphere->diameter * sphere->diameter
            - dist_proj_center * dist_proj_center);
            dist_origin_intersection = dist_origin_proj + dist_proj_intersection;
            ray->color = sphere->color;
            ray->bounce.pos = vectranslat(ray->pos, ray->dir, dist_origin_intersection);
            ray->bounce.surface_normal = vecnorm(vecnew(vectranslat(ray->pos, ray->dir, dist_origin_intersection), sphere->pos));
            *closest = dist_origin_intersection;
            return (1);
        }
        return (0);
    }
    dist_proj_intersection = sqrt(sphere->diameter * sphere->diameter
        - dist_proj_center * dist_proj_center);
    dist_origin_intersection = dist_origin_proj - dist_proj_intersection;
    if ((dist_origin_intersection > 0.1f) && (dist_origin_intersection < *closest))
    {
        ray->color = sphere->color;
        ray->bounce.surface_normal = vecnorm(vecnew(sphere->pos, vectranslat(ray->pos, ray->dir, dist_origin_intersection)));
        ray->bounce.pos = vectranslat(ray->pos, ray->dir, dist_origin_intersection);
        *closest = dist_origin_intersection;
    }
    dist_origin_intersection = dist_origin_proj + dist_proj_intersection;
    if ((dist_origin_intersection > 0.1f) && (dist_origin_intersection < *closest))
    {
        if (dist_origin_center < sphere->diameter - 0.1)
            ray->bounce.surface_normal = vecnorm(vecnew(vectranslat(ray->pos, ray->dir, dist_origin_intersection), sphere->pos));
        else
            ray->bounce.surface_normal = vecnorm(vecnew(sphere->pos, vectranslat(ray->pos, ray->dir, dist_origin_intersection)));
        ray->color = sphere->color;
        ray->bounce.pos = vectranslat(ray->pos, ray->dir, dist_origin_intersection);
        *closest = dist_origin_intersection;
    }
    if (tmp != *closest)
        return (1);
    return (0);
}
