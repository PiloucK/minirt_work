/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 21:02:07 by user42            #+#    #+#             */
/*   Updated: 2020/11/10 16:46:31 by user42           ###   ########.fr       */
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
    
    cross1 = veccross(v_bottom_top, v_bottom_origin); //A0xAB
    cross2 = veccross(ray->dir, v_bottom_top); //VxAB
    
    dot1 = vecdotprod(v_bottom_top, v_bottom_top); //ab2
    
    dot2 = vecdotprod(cross2, cross2); //a
    dot3 = 2 * vecdotprod(cross2, cross1); //b
    
    dot4 = vecdotprod(cross1, cross1) - (pow(cylinder->radius, 2) * dot1); //c
    tmp = dot3 * dot3 - 4 * dot2 * dot4; //d
    if (tmp < 0)
        ret = 0;
    // printf("-----------------\n");
    // printf("%lf\n", tmp);
    time = (dot3 - sqrt(tmp)) / (2 * dot2);
    // printf("%lf\n", time);
    if (time < 0)
        ret = 0;
    hitpoint = vectranslat(ray->pos, ray->dir, time);
    proj = vecsum(bottom, vecscale(v_bottom_top, vecdotprod(v_bottom_top, vecsub(hitpoint, bottom))));
    // if (vecmag(
    //     vecnew(
            
    //     )
    // ) < cylinder->radius)
    //     ret = 1;
// ((P(t) - A) x (B - A)) ^ 2 = r ^ 2 * ((B - A) . (B - A))
    //--------------------------------------------------------------------------
    // Ray : P(t) = O + V * t
    // Cylinder [O, D, r].
    // point Q on cylinder if ((Q - O) x D)^2 = r^2
    //
    // Cylinder [A, B, r].
    // Point P on infinite cylinder if ((P - A) x (B - A))^2 = r^2 * (B - A)^2
    // expand : ((O - A) x (B - A) + t * (V x (B - A)))^2 = r^2 * (B - A)^2
    // equation in the form (X + t * Y)^2 = d
    // where : 
    //  X = (O - A) x (B - A)
    //  Y = V x (B - A)
    //  d = r^2 * (B - A)^2
    // expand the equation :
    // t^2 * (Y . Y) + t * (2 * (X . Y)) + (X . X) - d = 0
    // => second order equation in the form : a*t^2 + b*t + c = 0 where
    // a = (Y . Y)
    // b = 2 * (X . Y)
    // c = (X . X) - d
    //--------------------------------------------------------------------------Vector AB = (B - A);Vector AO = (O - A);Vector AOxAB = (AO ^ AB); 
    // cross productVector VxAB  = (V ^ AB); 
    // cross productfloat  ab2   = (AB * AB); 
    // dot productfloat a      = (VxAB * VxAB); 
    // dot productfloat b      = 2 * (VxAB * AOxAB); 
    // dot productfloat c      = (AOxAB * AOxAB) - (r*r * ab2);
    // solve second order equation : a*t^2 + b*t + c = 0



                                    // printf("---------------------------------------\n");
                                    // double      test;
                                    // t_vec3lf    v_test;
                                    // v_test = vecnorm(veccross(cylinder->dir, ray->dir));
                                    // v_test = veccross(v_test, cylinder->dir);
                                    // test = plane_dist(*closest, ray, &v_test, cylinder->pos);
                                    // printf("%lf\n", test);
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
