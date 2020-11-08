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
    intersect_plane(double *closest, t_ray *ray, void *elem_detail)
{
    t_plane     *plane;
    double      dist;

    plane = (t_plane *)elem_detail;
    if (!(dist = plane_dist(*closest, ray, &(plane->dir))))
        return (0);
    ray->color = plane->color;
    ray->bounce.pos = vectranslat(ray->pos, ray->dir, dist);
    ray->bounce.surface_normal = plane->dir;
    *closest = dist;
    return (1);
}
