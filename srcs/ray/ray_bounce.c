/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_bounce.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 23:23:19 by user42            #+#    #+#             */
/*   Updated: 2020/11/19 11:03:37 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void
    ray_bounce(t_ray *ray, t_info *info, t_elem_list *hit_elem, int *i)
{
    t_light_list    *light;
    t_color         lights_sum;
    t_ray           b;

    if (--*i >= 0 && hit_elem)
    {
        lights_sum = color_mult(info->ambiant->color, info->ambiant->ratio);
        b.pos = ray->b.pos;
        light = info->first_light;
        while (light)
        {
            b.dir = vecnorm(vecnew(b.pos, light->pos));
            if (!find_closest(&b, info,
                vecmag(vecnew(b.pos, light->pos)) - EPSY, *i))
            {
        // printf("%lf | %lf | %lf\n", lights_sum.r, lights_sum.g, lights_sum.b);
                if (color_add(&lights_sum, color_mult(color_mult(light->color,
                    light->ratio), util_clamp(vecdot(b.dir, ray->b.n), 0, 1))))
                    break ;
            }
            light = light->next_light;
        }
        // printf("%lf | %lf | %lf\n", ray->color.r, ray->color.g, ray->color.b);
        color_sub(&(ray->color), lights_sum);
    }
    else
        ray->color = color_mult(ray->color, 0);
}
