/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_square.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 16:03:47 by user42            #+#    #+#             */
/*   Updated: 2020/11/14 14:47:21 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"


int
    intersect_square(double *closest, t_ray *ray, void *elem_detail)
{
    t_square    *square;
    double      dist;
    t_vec3lf    v_right;
    t_vec3lf    v_up;
    t_vec3lf    hitpoint;

    square = elem_detail;
    if (!(dist = plane_dist(*closest, ray, &(square->dir), square->pos)))
        return (0);
    hitpoint = vectranslat(ray->pos, ray->dir, dist);
    v_right = vecnorm(veccross(square->dir, vecnewvalues(0,0,1)));
    v_right.x = vecis(v_right, 0, 0, 0)
        + v_right.x * !vecis(v_right, 0, 0, 0);
    v_up = vecnorm(veccross(square->dir, v_right));
    if (vecdot(hitpoint, v_right) > square->height / 2
        || -vecdot(hitpoint, v_right) > square->height / 2
        || vecdot(hitpoint, v_up) > square->height / 2
        || -vecdot(hitpoint, v_up) > square->height / 2)
        return (0);
    set_bounce(ray, square->color, hitpoint, square->dir);
    *closest = dist;
    return (1);
}
