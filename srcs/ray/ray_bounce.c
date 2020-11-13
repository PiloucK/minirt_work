/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_bounce.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 23:23:19 by user42            #+#    #+#             */
/*   Updated: 2020/11/13 00:38:58 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void
    ray_bounce(t_ray *ray, t_info *info, t_elem_list *hit_elem, int *i)
{
    t_light_list    *cur_light;
    t_color         lights_sum;
    t_ray           bounce;

    if (--*i >= 0 && hit_elem)
    {
        lights_sum = color_mult(info->ambiant->color, info->ambiant->ratio);
        bounce.pos = ray->bounce.pos;
        cur_light = info->first_light;
        while (cur_light)
        {
            bounce.dir = vecnorm(vecnew(bounce.pos, cur_light->pos));
            if (!find_closest(&bounce, info,
                vecmag(vecnew(bounce.pos, cur_light->pos)) - EPSY, *i))
            {
                if (color_add(&lights_sum,
                    color_mult(color_mult(cur_light->color, cur_light->ratio),
                    util_clamp(vecdotprod(bounce.dir, ray->bounce.n), 0, 1))))
                    break ;
            }
            cur_light = cur_light->next_light;
        }
        color_sub(&(ray->color), lights_sum);
    }
    else
        ray->color = color_mult(ray->color, 0);
}
