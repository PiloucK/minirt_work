/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_plane->c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 12:18:03 by user42            #+#    #+#             */
/*   Updated: 2020/11/08 18:08:46 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double
    plane_dist(double closest, t_ray *ray, t_vec3lf *plane_normal, t_vec3lf o)
{
    double      dist;

    *plane_normal = vecnorm(*plane_normal);
    dist = vecdot(ray->dir, *plane_normal);
    if (!dist)
        return (0);
    if (dist < 0)
        *plane_normal = vecscale(*plane_normal, -1);
    dist = -vecdot(vecnew(o, ray->pos), *plane_normal)
        / vecdot(ray->dir, *plane_normal);
    if (dist < EPSY || dist > closest)
        return (0);
    return (dist);
}

int
    intersect_plane(double *closest, t_ray *ray, void *elem_detail)
{
    t_plane     *plane;
    double      dist;

    plane = elem_detail;
    if (!(dist = plane_dist(*closest, ray, &(plane->dir), plane->pos)))
        return (0);
    *closest = dist;
    set_bounce(ray, plane->color, vectranslat(ray->pos, ray->dir, dist),
        plane->dir);
    return (1);
}
