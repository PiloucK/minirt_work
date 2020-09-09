/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 15:46:24 by clkuznie          #+#    #+#             */
/*   Updated: 2020/09/09 19:53:50 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// t_parse_fnct    parse_array[256];

int		key_hooked(int key, void *arg)
{
    ft_printf("key :%i\n", key);
	if (key == KEY_ESC)
		err_close(arg);
	return (0);
}

void
    parsed_check(t_info *info)
{
    (void)info;
    // ft_printf("%p\n", info->win);
    // ft_printf("\nvalues size_x/size_y =%i/%i\n", info->win->size_x, info->win->size_y);
    // info->win.ptr = mlx_new_window(info->mlx, info->win.size_x, info->win.size_x, "MiniRT");

    // mlx_hook(info->win.ptr, 17, 0, err_close, &info);
    // mlx_key_hook(info->win.ptr, &key_hooked, &info);
    // mlx_loop(info->win.ptr);
}

void
    parse_rafl(char ***object_params, t_info *info)
{
    (void)object_params;
    err_print(3, info, "RAFL Unknown object type");
}

int
    main(int ac, char **av)
{
    t_info  *info;

    arg_reading(ac, av, &info);
    info_free(info);
    err_close(NULL);
}
