/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 21:02:07 by user42            #+#    #+#             */
/*   Updated: 2020/11/09 21:18:10 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double
    intersect_disk(double *closest, t_ray *ray, t_cylinder *cylinder, t_vec3lf center)
{
    double      dist;
    t_vec3lf    hitpoint;
    t_vec3lf    disk_normal;

    disk_normal = cylinder->dir;
    if (!(dist = plane_dist(*closest, ray, &disk_normal, center)))
        return (0);
    hitpoint = vectranslat(ray->pos, ray->dir, dist);
    if (vecmag(vecnew(hitpoint, center)) > cylinder->radius)
        return (0);
    ray->bounce.pos = hitpoint;
    ray->bounce.n = vecscale(disk_normal, -1);
    ray->color = cylinder->color;
    *closest = dist;
    return (1);
}

double
    intersect_cylinder(double *closest, t_ray *ray, void *elem_detail)
{
    double      ret;
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
    ret = 1;
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
    dot4 = vecdotprod(cross1, cross1) * (cylinder->radius * cylinder->radius * dot1);
    tmp = dot3 * dot3 - 4 * dot2 * dot4;
    if (tmp < 0)
        ret = 0;
    time = (-dot3 - sqrt(tmp)) / (2 * dot2);
    if (time < 0)
        ret = 0;
    hitpoint = vectranslat(ray->pos, ray->dir, time);
    proj = vecsum(bottom, vecscale(v_bottom_top, vecdotprod(v_bottom_top, vecsub(hitpoint, bottom))));
    // if (vecmag(
    //     vecnew(
            
    //     )
    // ) < cylinder->radius)
    //     ret = 1;
    printf("---------------------------------------\n");
    double      test;
    t_vec3lf    v_test;
    v_test = vecnorm(veccross(cylinder->dir, ray->dir));
    v_test = veccross(v_test, cylinder->dir);
    test = plane_dist(*closest, ray, &v_test, cylinder->pos);
    printf("%lf\n", test);
    // print_vec3lf(vecscale(cylinder->dir, test));
    // disk_normal = cylinder->dir;
    // if (!(dist = intersect_disk(*closest, ray, &(cylinder->dir), cylinder->pos, cylinder->radius)) && !(intersect_disk(dist, ray, &disk_normal, vectranslat(cylinder->pos, cylinder->dir, cylinder->height), cylinder->radius)))
    //     return (0);
    // disk_normal = cylinder->dir;
    // if (intersect_disk(dist, ray, &disk_normal, vectranslat(cylinder->pos, cylinder->dir, cylinder->height), cylinder->radius))
    // {
    //     printf("toto");
    //     dist = intersect_disk(dist, ray, &(cylinder->dir), vectranslat(cylinder->pos, cylinder->dir, cylinder->height), cylinder->radius);
    // }
    // hitpoint = vectranslat(ray->pos, ray->dir, dist);
    if (ret)
    {
        ray->bounce.pos = hitpoint;
        ray->bounce.n = vecnorm(vecnew(proj, hitpoint));
        ray->color = cylinder->color;
        *closest = time;
    }
    double toto;
    toto = intersect_disk(closest, ray, cylinder, cylinder->pos);
    if (toto)
        ret = toto;
    toto = intersect_disk(closest, ray, cylinder, vectranslat(cylinder->pos, cylinder->dir, cylinder->height));
    if (toto)
        ret = toto;
    return (ret);
}
