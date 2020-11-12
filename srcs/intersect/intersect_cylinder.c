/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 21:02:07 by user42            #+#    #+#             */
/*   Updated: 2020/11/12 12:00:57 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int
    intersect_disk(double *closest, t_ray *ray, t_cylinder *cylinder, t_vec3lf center)
{
    double      dist;
    t_vec3lf    hitpoint;
    t_vec3lf    disk_normal;

    disk_normal = cylinder->dir;
    if (!(dist = plane_dist(*closest, ray, &disk_normal, center)))
        return (0);
    hitpoint = vectranslat(ray->pos, ray->dir, dist);
    if (vecmag(vecnew(hitpoint, center)) > cylinder->r)
        return (0);
    ray->bounce.pos = hitpoint;
    ray->bounce.n = vecscale(disk_normal, -1);
    ray->color = cylinder->color;
    *closest = dist;
    return (1);
}

int
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
    t_vec3lf    v_bottom_origin;
    (void)v_bottom_origin;
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
    double      do_bounce;

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
    
    v_bottom_top = vecnew(bottom, top); //AB
    v_bottom_origin = vecnew(bottom, ray->pos); //A0
    
    cross1 = veccross(v_bottom_origin, v_bottom_top); //A0xAB
    cross2 = veccross(ray->dir, v_bottom_top); //VxAB
    
    dot1 = vecdotprod(v_bottom_top, v_bottom_top); //ab2
    
    dot2 = vecdotprod(cross2, cross2); //a
    dot3 = 2 * vecdotprod(cross2, cross1); //b
    
    dot4 = vecdotprod(cross1, cross1) - (pow(cylinder->r, 2) * dot1); //c
    tmp = pow(dot3, 2) - 4 * dot2 * dot4; //d
    if (tmp < 0)
        ret = 0;
    time = (-dot3 + sqrt(tmp)) / (2 * dot2);
    if (time < EPSY || time > *closest)
        ret = 0;
    else
        do_bounce = time;
    time = (-dot3 - sqrt(tmp)) / (2 * dot2);
    if (time > EPSY && time < do_bounce)
    {
        ret = 1;
       do_bounce = time;
    }
    hitpoint = vectranslat(ray->pos, ray->dir, time);
    proj = vecsum(cylinder->pos, vecscale(cylinder->dir, vecdotprod(cylinder->dir, vecnew(bottom, hitpoint))));
    if (vecdotprod(cylinder->dir, vecnew(bottom, hitpoint)) > vecmag(v_bottom_top))
        ret = 0;
    if (vecdotprod(cylinder->dir, vecnew(bottom, hitpoint)) < 0)
        ret = 0;
    if (ret)
    {
        ray->bounce.pos = hitpoint;
        ray->bounce.n = vecnorm(vecnew(proj, hitpoint));
        if (vecdotprod(ray->bounce.n, ray->dir) > 0)
            ray->bounce.n = vecscale(ray->bounce.n, -1);
        ray->color = cylinder->color;
        *closest = do_bounce;
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
