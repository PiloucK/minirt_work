/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_ray_gen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 18:44:24 by clkuznie          #+#    #+#             */
/*   Updated: 2020/10/23 11:11:52 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void
    camera_ray_gen(t_ray *ray, t_info *info, double i, double j)
{
    double  aspect_ratio;
    double  h;
    double  w;
    t_vec3lf    v_right;
    t_vec3lf    upguide;
    t_vec3lf    v_up;

    if (!info->cur_camera)
        err_print(4, info, "No camera found");
    upguide = vecnewvalues(0, 1, 0);
    ray->pos = info->cur_camera->pos;
    aspect_ratio = info->res->x / info->res->y;
    w = tan(info->cur_camera->fov / 2 * (PI / 180));
    h = w / aspect_ratio;
    ray->dir = info->cur_camera->dir;
    v_right = vecnorm(veccross(ray->dir, upguide));
    v_up = vecnorm(veccross(v_right, ray->dir));
    w *= i * 2 / info->res->x - 1;
    h *= j * 2 / info->res->y - 1;
    v_up = vecscale(v_up, h);
    v_right = vecscale(v_right, w);
    ray->dir = vecsum(ray->dir, v_right);
    ray->dir = vecsum(ray->dir, v_up);
    ray->dir = vecnorm(ray->dir);
}

// void
//     camera_ray_gen(t_ray *ray, t_info *info, int i, int j)
// {
//     // double  x;
//     // double  y;
//     // double  aspect_ratio;
//     // double  h;
//     // double  w;
//     double  dist;
//     // t_vec3lf    v_right;
//     // t_vec3lf    upguide;
//     // t_vec3lf    v_up;
//     (void)i;
//     (void)j;
//     // (void)h;

//     if (!info->cur_camera)
//         err_print(4, info, "No camera found");
//     // upguide = vecnewvalues(0.0, 1.0, 0.0);
//     ray->pos = info->cur_camera->pos;
//     dist = (info->res->x / 2) / tan(info->cur_camera->fov / 2 * (PI / 180));
    // printf("%lf\n",  dist);
//     ray->pos.x = i;
//     ray->pos.y = j;
//     ray->dir = info->cur_camera->dir;
//     // aspect_ratio = info->res->x / info->res->y;
//     // w = tan(info->cur_camera->fov / 2);
//     // h = w / aspect_ratio;
//     // ray->dir = info->cur_camera->dir;
//     // v_right = vecnorm(veccross(ray->dir, upguide));
//     // v_up = veccross(v_right, ray->dir);





    // printf("------\n");
    // print_vec3lf(v_right);
    // print_vec3lf(v_up);
    // print_vec3lf(ray->dir);
    // print_vec3lf(vecnorm(v_up));
    // print_vec3lf(ray->dir);
// }
