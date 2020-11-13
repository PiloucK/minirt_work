/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_closest.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 23:25:27 by user42            #+#    #+#             */
/*   Updated: 2020/11/12 22:54:09 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_elem_list     *
    find_closest(t_ray *ray, t_info *info, double closest, int i)
{
    t_elem_list     *cur_elem;
    t_elem_list     *closest_elem;
    
    cur_elem = info->first_elem;
    closest_elem = NULL;
    while (cur_elem)
    {
        if ((*g_intersect_arr[cur_elem->id])(&closest, ray,
            cur_elem->elem_detail))
            closest_elem = cur_elem;
        cur_elem = cur_elem->next_elem;
    }
    if (i)
        ray_bounce(ray, info, closest_elem, &i);
    return (closest_elem);
}
