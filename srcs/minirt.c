/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 08:59:45 by clkuznie          #+#    #+#             */
/*   Updated: 2020/07/30 08:59:46 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		ft_close(t_info *info)
{
    mlx_destroy_window(info->mlx, info->win.ptr);
	exit(0);
	return (1);
}

int		ft_key(int key, void *arg)
{
	if (key == ESC)
		ft_close(arg);
	return (1);
}


int
    main(int ac, char **av)
{
    (void)av;
    if (ac == 1)
        arg_err_print(1);
    else
    {
        t_info  info;

        info.mlx = mlx_init();
        info.win.ptr = mlx_new_window(info.mlx, 1000, 1000, "Title");

        mlx_hook(info.win.ptr, 2, 0, ft_key, &info);
        mlx_hook(info.win.ptr, 17, 0, ft_close, &info);
        mlx_loop(info.win.ptr);
    }
    return (0);
}
