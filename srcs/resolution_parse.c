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

void
    resolution_parse(char **object_params, t_info *info)
{
    if (util_object_params_count(object_params) != 3)
        err_print(3, info, "Wrong resolution line format");
    print_infos(info);
    is_full_digits(object_params[1]);
    // print_infos(info);
    //  tmp->size_x = ft_atoi(object_params[1]);
    // tmp->size_y = ft_atoi(object_params[2]);
    // info->win = tmp;
    // info->win.size_x = tmp->size_x;
    // info->win.size_y = tmp->size_y;
    // print_infos(info);
    // print_win_info(info);
        // info->mlx = mlx_init();
// ft_printf("%p\n", info->mlx);
    // info->win->size_x = tmp->size_x;
    // info->win->size_y = tmp->size_y;
    // ft_printf("%i, %i\n", info->win->size_x, info->win->size_y);

// tmp->ptr = mlx_new_window(info->mlx, &tmp->size_x, &tmp->size_y, "MiniRT");
    // info->win.ptr = mlx_new_window(info->mlx, 1000, 1000, "MiniRT");
    // mlx_hook(info->win.ptr, 17, 0, err_close, &info);
    // mlx_key_hook(info->win.ptr, &key_hooked, &info);
    // mlx_loop(info->win.ptr);
}
