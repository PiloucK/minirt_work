/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_plane.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 12:18:03 by user42            #+#    #+#             */
/*   Updated: 2020/11/07 22:39:45 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double
    intersect_plane(double *closest, t_ray *ray, void *elem_detail)
{
    t_plane     plane;
    double      denom;
    t_vec3lf    v_plane_origin;

    plane = *(t_plane *)elem_detail;
    v_plane_origin = vecsub(plane.pos, ray->pos);
    denom = vecdotprod(v_plane_origin, plane.dir) / vecdotprod(plane.dir, ray->dir);
    if (denom > 0.1 && denom < *closest)
    {
        ray->color = plane.color;
        ray->bounce.pos = vectranslat(ray->pos, ray->dir, denom);
        ray->bounce.surface_normal = vecscale(plane.dir, -1);
        *closest = denom;
        return (1);
    }
    return (0);
}
