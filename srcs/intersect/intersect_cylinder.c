/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 21:02:07 by user42            #+#    #+#             */
/*   Updated: 2020/11/08 22:34:16 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double
    intersect_disk(double closest, t_ray *ray, t_vec3lf *plane_normal, t_vec3lf center, double diameter)
{
    double      dist;
    t_vec3lf    hitpoint;

    if (!(dist = plane_dist(closest, ray, plane_normal)))
        return (0);
    hitpoint = vectranslat(ray->pos, ray->dir, dist);
    if (vecmag(vecnew(hitpoint, center)) > diameter)
        return (0);
    return (dist);
}

double
    intersect_cylinder(double *closest, t_ray *ray, void *elem_detail)
{
    t_cylinder  *cylinder;
    t_vec3lf    hitpoint;
    t_vec3lf    disk_normal;
    t_vec3lf    bottom;
    t_vec3lf    top;
    t_vec3lf    v_bottom_top;
    (void)v_bottom_top;
    t_vec3lf    v_origin_bottom;
    (void)v_origin_bottom;
    t_vec3lf    cross1;
    (void)cross1;
    t_vec3lf    cross2;
    (void)cross2;
    double      dot1;
    (void)dot1;
    double      dot2;
    (void)dot2;
    double      dot3;
    (void)dot3;
    double      dot4;
    (void)dot4;
    double      tmp;
    (void)tmp;
    double      time;
    (void)time;
    t_vec3lf    proj;
    (void)proj;
    
    double      dist;

(void)cylinder;
(void)hitpoint;
(void)disk_normal;
(void)dist;
(void)closest;
(void)ray;
(void)elem_detail;
(void)bottom;
(void)top;
    cylinder = (t_cylinder *)elem_detail;
    bottom = cylinder->pos;
    top = vectranslat(cylinder->pos, cylinder->dir, cylinder->height);
    v_bottom_top = vecnew(bottom, top);
    v_origin_bottom = vecnew(ray->pos, bottom);
    cross1 = veccross(v_bottom_top, v_origin_bottom);
    cross2 = veccross(ray->dir, v_bottom_top);
    dot1 = vecdotprod(v_bottom_top, v_bottom_top);
    dot2 = vecdotprod(cross2, cross2);
    dot3 = 2 * vecdotprod(cross2, cross1);
    dot4 = vecdotprod(cross1, cross1) * (cylinder->diameter * cylinder->diameter * dot1);
    tmp = dot3 * dot3 - 4 * dot2 * dot4;
    if (tmp < 0)
        return (0);
    time = (-dot3 - sqrt(tmp)) / (2 * dot2);
    if (time < 0)
        return (0);
    hitpoint = vectranslat(ray->pos, ray->dir, time);
    proj = vecsum(bottom, vecscale(v_bottom_top, vecdotprod(v_bottom_top, vecsub(hitpoint, bottom))));
    // disk_normal = cylinder->dir;
    // if (!(dist = intersect_disk(*closest, ray, &(cylinder->dir), cylinder->pos, cylinder->diameter)) && !(intersect_disk(dist, ray, &disk_normal, vectranslat(cylinder->pos, cylinder->dir, cylinder->height), cylinder->diameter)))
    //     return (0);
    // disk_normal = cylinder->dir;
    // if (intersect_disk(dist, ray, &disk_normal, vectranslat(cylinder->pos, cylinder->dir, cylinder->height), cylinder->diameter))
    // {
    //     printf("toto");
    //     dist = intersect_disk(dist, ray, &(cylinder->dir), vectranslat(cylinder->pos, cylinder->dir, cylinder->height), cylinder->diameter);
    // }
    // hitpoint = vectranslat(ray->pos, ray->dir, dist);
    ray->bounce.pos = hitpoint;
    ray->bounce.surface_normal = vecnorm(vecnew(proj, hitpoint));
    ray->color = cylinder->color;
    *closest = time;
    return (1);
}
