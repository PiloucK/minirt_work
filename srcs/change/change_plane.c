/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_plane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 20:04:24 by user42            #+#    #+#             */
/*   Updated: 2020/11/12 23:13:01 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void
    change_plane(void *elem_detail, int key, t_info *info)
{
    t_plane     *plane;

    plane = elem_detail;
    if (!info->various.rot)
        plane->pos = translate(plane->pos, key, info);
    else
        plane->dir = 
            rotate(plane->dir, info->cur_camera->elem_detail, key, info);
}
