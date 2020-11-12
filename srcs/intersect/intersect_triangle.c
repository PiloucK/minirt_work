/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_triangle.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 10:44:41 by user42            #+#    #+#             */
/*   Updated: 2020/11/12 12:02:24 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int
    intersect_triangle(double *closest, t_ray *ray, void *elem_detail)
{
    t_triangle  *tr;
    t_vec3lf    side;
    t_vec3lf    hitpoint;
    t_vec3lf    v_vert_hitpoint;
    double      dist;
    double      in;

    tr = elem_detail;
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
