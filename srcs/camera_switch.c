/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_switch.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 19:43:45 by clkuznie          #+#    #+#             */
/*   Updated: 2020/09/30 22:42:01 by clkuznie         ###   ########.fr       */
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
    info->cur_camera = cur_elem->elem_detail;
printf("%lf\n", info->cur_camera->pos.x);
    screen_scan(info);
}