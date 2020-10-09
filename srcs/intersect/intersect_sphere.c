/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_sphere.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 08:26:07 by clkuznie          #+#    #+#             */
/*   Updated: 2020/10/09 11:50:45 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double
    intersect_sphere(double closest, t_ray *ray, void *elem_detail)
{
    t_sphere    *sphere;
    t_vec3lf    v_origin_center;
    double      dist_origin_center_onray;
    double      dist_origin_center;
    double      dist_ray_center;
    double      tmp;

    sphere = elem_detail;
    if (!sphere)
        return (closest);
// printf("-----\n");
    v_origin_center = vecnew(ray->pos, sphere->pos);
// print_vec3lf(v_origin_center);
    dist_origin_center_onray = vecdotprod(v_origin_center, ray->dir);
// printf("distance from origin to center on ray %lf\n", dist_origin_center_onray);
    dist_origin_center = vecmag(v_origin_center);
// printf("distance from ray origin to center %lf\n", dist_origin_center);
    dist_ray_center = vecprod(
        v_origin_center, ray->dir, vecangle(v_origin_center, ray->dir));
// printf("distance from ray to center %lf\n", dist_ray_center);
    if (dist_ray_center > sphere->diameter)
        return (closest);
    if (dist_origin_center_onray <= 0)
    {
        tmp = sphere->diameter;
        if (dist_origin_center < sphere->diameter)
        {
            if (dist_origin_center)
                tmp = sqrt(sphere->diameter * sphere->diameter
                    - dist_ray_center * dist_ray_center)
                    - util_absvalue(dist_origin_center_onray) * (dist_origin_center != 0)
                    + sphere->diameter * !dist_origin_center;
// printf("%lf\n", tmp);
            if ((tmp > 0.1f) && (tmp < closest))
            {
    ray->color = sphere->color.r;
    ray->color = (ray->color << 8) + sphere->color.g;
    ray->color = (ray->color << 8) + sphere->color.b;
                closest = tmp;
            }
// printf("%lf\n", tmp + 2 * util_absvalue(dist_origin_center_onray));
        }
        return  (closest);
    }
    if (dist_ray_center > sphere->diameter)
        return (closest);
    tmp = sqrt(sphere->diameter * sphere->diameter
                    - dist_ray_center * dist_ray_center);
    dist_origin_center_onray -= tmp;
    if ((dist_origin_center_onray > 0.1f) && (dist_origin_center_onray < closest))
    {
    ray->color = sphere->color.r;
    ray->color = (ray->color << 8) + sphere->color.g;
    ray->color = (ray->color << 8) + sphere->color.b;
        closest = dist_origin_center_onray;
    }
    dist_origin_center_onray += tmp * 2;
    if ((dist_origin_center_onray > 0.1f) && (dist_origin_center_onray < closest))
    {
    ray->color = sphere->color.r;
    ray->color = (ray->color << 8) + sphere->color.g;
    ray->color = (ray->color << 8) + sphere->color.b;
        closest = dist_origin_center_onray;
    }
    return (closest);
}
