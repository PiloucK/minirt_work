/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_switch.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 19:43:45 by clkuznie          #+#    #+#             */
/*   Updated: 2020/11/12 11:21:52 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_elem_list  *
    next_camera(t_elem_list *elem)
{
    t_elem_list     *cur_elem;
    
    cur_elem = elem;
    while (cur_elem && cur_elem->id != C)
        cur_elem = cur_elem->next_elem;
    return (cur_elem);
}

void
                    camera_switch(t_info *info)
{
    t_elem_list     *cur_elem;

    cur_elem = info->first_elem;
    if (!info->cur_camera)
    {
        cur_elem = next_camera(info->first_elem);
        if (!cur_elem)
            err_print(4, info, "No camera found");
        info->cur_camera = cur_elem->elem_detail;
        return ;
    }
    while (cur_elem->elem_detail != info->cur_camera)
        cur_elem = cur_elem->next_elem;
    cur_elem = next_camera(cur_elem->next_elem);
    if (!cur_elem)
        cur_elem = next_camera(info->first_elem);
    if (cur_elem->elem_detail == info->cur_camera)
        return ;
    info->cur_camera = cur_elem->elem_detail;
    fill_image(info);
    mlx_put_image_to_window (info->mlx, info->win, info->image.img, 0, 0);
}
