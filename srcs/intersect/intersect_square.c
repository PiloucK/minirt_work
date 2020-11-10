/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_square.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 16:03:47 by user42            #+#    #+#             */
/*   Updated: 2020/11/10 17:08:47 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"


double
    intersect_square(double *closest, t_ray *ray, void *elem_detail)
{
    t_square    *square;
    double      dist;
    t_vec3lf    v_right;
    t_vec3lf    v_up;
    t_vec3lf    hitpoint;

    square = (t_square *)elem_detail;
    if (!(dist = plane_dist(*closest, ray, &(square->dir), square->pos)))
        return (0);
    hitpoint = vectranslat(ray->pos, ray->dir, dist);
    v_right = vecnorm(veccross(square->dir, vecnewvalues(0,0,1)));
    v_right.x = vecis(v_right, 0, 0, 0)
        + v_right.x * !vecis(v_right, 0, 0, 0);
    v_up = vecnorm(veccross(square->dir, v_right));
    if (vecdotprod(hitpoint, v_right) > square->height / 2
        || -vecdotprod(hitpoint, v_right) > square->height / 2
        || vecdotprod(hitpoint, v_up) > square->height / 2
        || -vecdotprod(hitpoint, v_up) > square->height / 2)
        return (0);
    ray->bounce.pos = hitpoint;
    ray->bounce.n = vecscale(square->dir, -1);
    ray->color = square->color;
    *closest = dist;
    return (1);
}

    // t_triangle  *tr;
    // t_vec3lf    side;
    // t_vec3lf    hitpoint;
    // t_vec3lf    v_vert_hitpoint;
    // double      dist;
    // double      in;

    // tr = (t_triangle *)elem_detail;
    // if (!(dist = plane_dist(*closest, ray, &(tr->normal), tr->a)))
    //     return (0);
    // hitpoint = vectranslat(ray->pos, ray->dir, dist);
    // side = vecnew(tr->a, tr->b);
    // v_vert_hitpoint = vecnew(tr->a, hitpoint);
    // in = 0;
    // in += vecdotprod(tr->normal, veccross(side, v_vert_hitpoint)) > 0;
    // side = vecnew(tr->b, tr->c);
    // v_vert_hitpoint = vecnew(tr->b, hitpoint);
    // in += vecdotprod(tr->normal, veccross(side, v_vert_hitpoint)) > 0;
    // side = vecnew(tr->c, tr->a);
    // v_vert_hitpoint = vecnew(tr->c, hitpoint);
    // in += vecdotprod(tr->normal, veccross(side, v_vert_hitpoint)) > 0;
    // if (in != 0 && in != 3)
    //     return (0);
    // ray->bounce.pos = hitpoint;
    // ray->bounce.n = vecscale(tr->normal, -1);
    // ray->color = tr->color;
    // *closest = dist;
