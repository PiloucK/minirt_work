/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution_parse.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 15:45:29 by clkuznie          #+#    #+#             */
/*   Updated: 2020/08/06 15:45:30 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int
    is_full_digits(char *object_param)
{
    int     i;

    i = 0;
    while (ft_isdigit(object_param[i]))
        i++;
    return (!object_param[i]);
}

static void
    resize(t_info *info)
{
    int     display_x;
    int     display_y;

    mlx_get_screen_size(info->mlx, &display_x, &display_y);
    if (display_x < info->win.size_x)
        info->win.size_x = display_x;
    if (display_x < info->win.size_y)
        info->win.size_y = display_y;
}

void
    resolution_parse(char **object_params, t_info *info)
{
    if (util_object_params_count(object_params) != 3)
        err_print(3, info, "Wrong resolution line format");
    if (info->win.res_status)
        err_print(3, info, "Redefinition of 'R'");
    if (!is_full_digits(object_params[1]) || !is_full_digits(object_params[2]))
        err_print(3, info, "Only digits are allowed");
    info->win.size_x = ft_atoi(object_params[1]);
    info->win.size_y = ft_atoi(object_params[2]);
    if (!info->do_save)
        resize(info);
    if (info->win.size_x <= 0 || info->win.size_y <= 0)
        err_print(3, info, "Can't use suggested size");
    info->win.res_status = 1;
}
