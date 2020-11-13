/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_cylinder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 20:03:22 by user42            #+#    #+#             */
/*   Updated: 2020/11/12 23:26:05 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void
    change_cylinder(void *elem_detail, int key, t_info *info)
{
    t_cylinder     *cylinder;

    cylinder = elem_detail;
    if (!info->various.rot)
        cylinder->pos = translate(cylinder->pos, key, info);
    else
        cylinder->dir = 
            rotate(cylinder->dir, info->cur_camera->elem_detail, key, info);
    cylinder->height = var_scale(cylinder->height, key);
}
