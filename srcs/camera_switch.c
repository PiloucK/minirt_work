/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_switch.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 19:43:45 by clkuznie          #+#    #+#             */
/*   Updated: 2020/09/29 19:48:03 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void
    next_camera(t_info *info)
{
    t_elem_list     *cur_elem;

    cur_elem = info->first_elem;
    while (cur_elem)
    {
        if (cur_elem->id != C)
            cur_elem = cur_elem->next_elem;
    }
}
