/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_triangle.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 10:44:41 by user42            #+#    #+#             */
/*   Updated: 2020/11/09 21:17:58 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double
    plane_dist(double closest, t_ray *ray, t_vec3lf *plane_normal, t_vec3lf o)
{
    double      dist;

    // *plane_normal = vecnorm(*plane_normal);
    dist = vecdotprod(ray->dir, *plane_normal);
    if (!dist)
        return (0);
    if (dist < 0)
        *plane_normal = vecscale(*plane_normal, -1);
    dist = -vecdotprod(vecnew(o, ray->pos), *plane_normal)
        / vecdotprod(ray->dir, *plane_normal);
    if (dist < EPSY || dist > closest)
        return (0);
    return (dist);
}

double
    intersect_triangle(double *closest, t_ray *ray, void *elem_detail)
{
    t_triangle  *tr;
    t_vec3lf    side;
    t_vec3lf    hitpoint;
    t_vec3lf    v_vert_hitpoint;
    double      dist;
    double      in;

    tr = (t_triangle *)elem_detail;
    if (!(dist = plane_dist(*closest, ray, &(tr->normal), tr->a)))
        return (0);
    hitpoint = vectranslat(ray->pos, ray->dir, dist);
    side = vecnew(tr->a, tr->b);
    v_vert_hitpoint = vecnew(tr->a, hitpoint);
    in = 0;
    in += vecdotprod(tr->normal, veccross(side, v_vert_hitpoint)) > 0;
    side = vecnew(tr->b, tr->c);
    v_vert_hitpoint = vecnew(tr->b, hitpoint);
    in += vecdotprod(tr->normal, veccross(side, v_vert_hitpoint)) > 0;
    side = vecnew(tr->c, tr->a);
    v_vert_hitpoint = vecnew(tr->c, hitpoint);
    in += vecdotprod(tr->normal, veccross(side, v_vert_hitpoint)) > 0;
    if (in != 0 && in != 3)
        return (0);
    ray->bounce.pos = hitpoint;
    ray->bounce.n = vecscale(tr->normal, -1);
    ray->color = tr->color;
    *closest = dist;
    return (1);
}
