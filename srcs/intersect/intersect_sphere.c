/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_sphere.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 08:26:07 by clkuznie          #+#    #+#             */
/*   Updated: 2020/11/14 14:22:22 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// int
//     intersect_sphere(double *closest, t_ray *ray, void *elem_detail)
// {
//     t_sphere    *sphere;
//     double      quad[4];
//     t_vec3lf    hit;

//     sphere = elem_detail;
//     quad[0] = 2 * vecdot(ray->dir, ray->pos);
//     quad[1] = pow(vecmag(ray->pos), 2) - pow(sphere->r, 2);
//     if ((pow(quad[0], 2) - (4 * quad[1])) < 0)
//         return (0);
//     quad[2] = -0.5 * (quad[0]
//         + ((quad[0] < 0) * -1) + (quad[0] >= 0)
//         * sqrt(pow(quad[0], 2) - (4 * quad[1])));
//     quad[3] = quad[1] / quad[2];
//     hit = vectranslat(ray->pos, ray->dir, quad[1]);
//     if (quad[1] > EPSY && quad[1] < *closest && (*closest = quad[1]))
//         set_bounce(ray, sphere->color, hit, vecnew(sphere->pos, hit));
//     hit = vectranslat(ray->pos, ray->dir, quad[3]);
//     if (quad[3] > EPSY && quad[3] < *closest && (*closest = quad[3]))
//         set_bounce(ray, sphere->color, hit, vecnew(sphere->pos, hit));
//     return (1);
// }

int
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
    v_origin_center = vecnew(ray->pos, sphere->pos);
    dist_proj_center = vecprod(v_origin_center, ray->dir, vecangle(v_origin_center, ray->dir));
    if (dist_proj_center > sphere->r)
        return (0);
    dist_origin_proj = vecdot(v_origin_center, ray->dir);
    dist_origin_center = vecmag(v_origin_center);
    if (dist_origin_proj <= 0)
    {
        if (dist_origin_center < sphere->r - EPSY)
        {
            dist_proj_intersection = sqrt(pow(sphere->r, 2)
            - pow(dist_proj_center, 2));
            dist_origin_intersection = dist_origin_proj + dist_proj_intersection;
            ray->color = sphere->color;
            ray->b.pos = vectranslat(ray->pos, ray->dir, dist_origin_intersection);
            ray->b.n = vecnorm(vecnew(vectranslat(ray->pos, ray->dir, dist_origin_intersection), sphere->pos));
            *closest = dist_origin_intersection;
            return (1);
        }
        return (0);
    }
    dist_proj_intersection =  sqrt(pow(sphere->r, 2)
            - pow(dist_proj_center, 2));
    dist_origin_intersection = dist_origin_proj - dist_proj_intersection;
    if ((dist_origin_intersection > EPSY) && (dist_origin_intersection < *closest))
    {
        ray->color = sphere->color;
        ray->b.n = vecnorm(vecnew(sphere->pos, vectranslat(ray->pos, ray->dir, dist_origin_intersection)));
        ray->b.pos = vectranslat(ray->pos, ray->dir, dist_origin_intersection);
        *closest = dist_origin_intersection;
    }
    dist_origin_intersection = dist_origin_proj + dist_proj_intersection;
    if ((dist_origin_intersection > EPSY) && (dist_origin_intersection < *closest))
    {
        if (dist_origin_center < sphere->r - EPSY)
            ray->b.n = vecnorm(vecnew(vectranslat(ray->pos, ray->dir, dist_origin_intersection), sphere->pos));
        else
            ray->b.n = vecnorm(vecnew(sphere->pos, vectranslat(ray->pos, ray->dir, dist_origin_intersection)));
        ray->color = sphere->color;
        ray->b.pos = vectranslat(ray->pos, ray->dir, dist_origin_intersection);
        *closest = dist_origin_intersection;
    }
    if (tmp != *closest)
        return (1);
    return (0);
}
