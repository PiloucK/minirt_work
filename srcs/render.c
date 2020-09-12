/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 15:56:59 by clkuznie          #+#    #+#             */
/*   Updated: 2020/09/12 16:23:40 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void
    render(t_info *info)
{
    int     x;
    int     y;

    x = 0;
    while (x < info->res->x_size)
    {
        y = 0;
        while (y < info->res->y_size)
        {
    mlx_pixel_put (info->mlx, info->win, x, y, 0x00ff0000);
            y++;
        }
        x++;
    }
    (void)info;
}
