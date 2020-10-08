/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_sphere.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 08:26:07 by clkuznie          #+#    #+#             */
/*   Updated: 2020/10/07 15:58:00 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
 * Here "v_origin_center" is the vector from the ray origin to the sphere center and
 * "sr" is the distance between the sphere center to the ray
*/
double
    intersect_sphere(double closest, t_ray *ray, void *elem_detail)
{
    t_sphere    *sphere;
    t_vec3lf    v_origin_center;
    double      dist_ray_center;
    double      sr;
    double      tmp;

    sphere = elem_detail;
    if (!sphere)
        return (closest);
// printf("-----\n");
    v_origin_center = vecnew(&ray->pos,  &sphere->pos);
    dist_ray_center = vecdotprod(&v_origin_center, &ray->dir);
    // printf("dist ray to center %lf\n", dist_ray_center);
    sr = vecprod(&v_origin_center, &ray->dir, vecangle(&v_origin_center, &ray->dir));
    // printf("dist ray origin to center %lf\n", sr);
    // printf("bis dist ray origin to center %lf\n", vecmag(&v_origin_center));
    if (dist_ray_center < 0.0)
    {
    //     if (sr < sphere->diameter)
    //     {
    //         dist_ray_center = sqrt(sphere->diameter * sphere->diameter - sr * sr) + dist_ray_center;
    //         if ((dist_ray_center > 0.1f) && (dist_ray_center < closest))
    //             closest = dist_ray_center;
    //         // printf("closest = %lf\n", closest);
    // ray->color = sphere->color.r;
    // ray->color = (ray->color << 8) + sphere->color.g;
    // ray->color = (ray->color << 8) + sphere->color.b;
    //     }
        return  (closest);
    }
    // printf("%lf\n", sphere->diameter);
    if (sr > sphere->diameter)
        return (closest);
    ray->color = sphere->color.r;
    ray->color = (ray->color << 8) + sphere->color.g;
    ray->color = (ray->color << 8) + sphere->color.b;
    tmp = sqrt(sphere->diameter * sphere->diameter - sr * sr);
    dist_ray_center -= tmp;
    if ((dist_ray_center > 0.1f) && (dist_ray_center < closest))
        closest = dist_ray_center;
    dist_ray_center += tmp * 2;
    if ((dist_ray_center > 0.1f) && (dist_ray_center < closest))
        closest = dist_ray_center;
    // printf("closest = %lf\n", closest);
    return (closest);
}
