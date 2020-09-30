/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 15:56:59 by clkuznie          #+#    #+#             */
/*   Updated: 2020/09/29 18:49:55 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_intersect_fnct    intersect_arr[256];

double
    intersect_rafl(double closest, t_ray *ray, void *elem_detail)
{
    (void)closest;
    (void)ray;
    (void)elem_detail;
    return (closest);
}

double
    intersect_sphere(double closest, t_ray *ray, void *elem_detail)
{
    t_sphere    *sphere;
    t_pos       distance;
    t_pos       proj;
    double      B, D, dist;
    double      t0, t1;
    
    sphere = elem_detail;
    if (!sphere)
        return (closest);
    distance.x = sphere->pos.x - ray->pos.x;
    distance.y = sphere->pos.y - ray->pos.y;
    distance.z = sphere->pos.z - ray->pos.z;
    proj.x = distance.x * ray->dir.xdir;
    proj.y = distance.y * ray->dir.ydir;
    proj.z = distance.z * ray->dir.zdir;
    distance.x *= distance.x;
    distance.y *= distance.y;
    distance.z *= distance.z;
    dist = sqrt((distance.x + distance.y + distance.z));
    B = proj.z;
    D = B * B - dist * dist + sphere->diameter * sphere->diameter;
    if (D < 0.0)
        return  (closest);
    t0 = B - sqrt(D);
    t1 = B + sqrt(D);
    if (t0 > 0.1 && t0 < closest)
        closest = t0;
    if (t1 > 0.1 && t1 < closest)
        closest = t1;
    ray->color = sphere->color.r;
    ray->color = (ray->color << 8) + sphere->color.g;
    ray->color = (ray->color << 8) + sphere->color.b;
    return (closest);
}

void
    intersect_arr_init()
{
    int             i;
    
    i = 0;
    while (i < 256)
        intersect_arr[i++] = intersect_rafl;
    intersect_arr[SP] = intersect_sphere;
}

static double
    intersection(t_ray *ray, t_info *info)
{
    t_elem_list     *cur_elem;
    double          closest;
    
    cur_elem = info->first_elem;
    closest = 1000000000;
    ray->color = info->ambiant->color.r * info->ambiant->lum;
    ray->color = (ray->color << 8) + info->ambiant->color.g * info->ambiant->lum;
    ray->color = (ray->color << 8) + info->ambiant->color.b * info->ambiant->lum;
    while (cur_elem)
    {
        closest = (*intersect_arr[cur_elem->id])(closest, ray, cur_elem->elem_detail);
        cur_elem = cur_elem->next_elem;
    }
    return (closest);
}

void
    screen_scan(t_info *info)
{
    int     x;
    int     y;
    t_ray   ray;

    x = 0;
    ray.pos.z = -1000.0;
    ray.dir.xdir = 0.0;
    ray.dir.ydir = 0.0;
    ray.dir.zdir = 1.0;;
    // ray_gen(&ray, info);
    intersect_arr_init();
    while (x < info->res->x_size)
    {
        y = 0;
        while (y < info->res->y_size)
        {
            ray.pos.x = x;
            ray.pos.y = y;
            intersection(&ray, info);
            mlx_pixel_put (info->mlx, info->win, x, y, ray.color);
            y++;
        }
        x++;
    }
}
