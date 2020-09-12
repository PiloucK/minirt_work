/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 15:56:59 by clkuznie          #+#    #+#             */
/*   Updated: 2020/09/12 19:21:31 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_sphere *
    find_next_sphere(t_elem_list *first_elem)
{
    t_elem_list  *cur_elem;
    
    cur_elem = first_elem;
    while (cur_elem)
    {
        if (cur_elem->id == SP)
        {
            return (cur_elem->elem_detail);
        }
        cur_elem = cur_elem->next_elem;
    }
    return (NULL);
}

static int
    ray_calc(t_ray *ray, t_info *info)
{
    t_sphere    *sphere;
    t_pos       distance;
    t_pos       proj;
    double      B, D, dist;

    sphere = find_next_sphere(info->first_elem);
    if (!sphere)
        return 0;
printf("sphere infos :\npos = %lf, %lf, %lf\nsize = %lf\n", sphere->pos.x, sphere->pos.y, sphere->pos.z, sphere->diameter);
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
        return  0;
    double t0 = B - sqrt(D);
    double t1 = B + sqrt(D);
    int ret = 0;
    double t = 1000000000;
    if (t0 > 0.1 && t0 < t)
    {
        t = t0;
        ret = 1;
    }
    if (t1 > 0.1 && t1 < t)
    {
        t = t1;
        ret = 1;
    }
    return (ret);
}

void
    render(t_info *info)
{
    int     x;
    int     y;
    t_ray   ray;

    x = 0;
    ray.pos.z = -1000.0;
    ray.dir.xdir = 0.0;
    ray.dir.ydir = 0.0;
    ray.dir.zdir = 1.0;
    while (x < info->res->x_size)
    {
        y = 0;
        while (y < info->res->y_size)
        {
            ray.pos.x = x;
            ray.pos.y = y;
            if (ray_calc(&ray, info))
                mlx_pixel_put (info->mlx, info->win, x, y, 0x00ff0000);
            else
                mlx_pixel_put (info->mlx, info->win, x, y, 0x0000ff00);
            y++;
        }
        x++;
    }
}
