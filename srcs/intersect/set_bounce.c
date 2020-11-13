/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_bounce.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 17:42:36 by user42            #+#    #+#             */
/*   Updated: 2020/11/13 18:17:36 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void
    set_bounce(t_ray *ray, t_color color, t_vec3lf pos, t_vec3lf n)
{
    ray->color = color;
    ray->b.pos = pos;
    if (vecdot(ray->dir, n) > 0)
        ray->b.n = vecscale(vecnorm(n), -1);
    ray->b.n = vecnorm(n);
}
