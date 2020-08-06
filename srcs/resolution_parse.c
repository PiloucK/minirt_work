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

void
    resolution_parse(char **object_params, t_info *info)
{
    t_win   *tmp;

    if (util_object_params_count(object_params) != 3)
        err_print(3, info, "Wrong resolution line format");
    // if (!(info->win = malloc(sizeof(t_win))))
    //     err_print(2, info, NULL);
    print_infos(info);
    if (!(tmp = malloc(sizeof(t_win))))
        err_print(2, info, NULL);
    tmp->size_x = ft_atoi(object_params[1]);
    tmp->size_y = ft_atoi(object_params[2]);
    info->win = tmp;
    info->win->size_x = tmp->size_x;
    info->win->size_y = tmp->size_y;
    print_infos(info);
    print_win_info(info);
        // info->mlx = mlx_init();
// ft_printf("%p\n", info->mlx);
    // info->win->size_x = tmp->size_x;
    // info->win->size_y = tmp->size_y;
    // ft_printf("%i, %i\n", info->win->size_x, info->win->size_y);

// tmp->ptr = mlx_new_window(info->mlx, &tmp->size_x, &tmp->size_y, "MiniRT");
    // info->win->ptr = mlx_new_window(info->mlx, info->win->size_x, info->win->size_x, "MiniRT");
    // mlx_hook(info->win->ptr, 17, 0, err_close, &info);
    // mlx_key_hook(info->win->ptr, &key_hooked, &info);
    // mlx_loop(info->win->ptr);
}
