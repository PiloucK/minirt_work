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

int		err_close(t_info *info)
{
    if (!info)
        exit(EXIT_FAILURE);
    mlx_destroy_window(info->mlx, info->win.ptr);
	exit(0);
}

int		key_hooked(int key, void *arg)
{
    ft_printf("key :%i\n", key);
	if (key == KEY_ESC)
		err_close(arg);
	return (0);
}

bool	iswrong_file_format(char *filename)
{
	int	i;

	i = ft_strlen(filename);
	return (i < 4 ||
            filename[i - 3] != '.' ||
			filename[i - 2] != 'r' ||
			filename[i - 1] != 't');
}

void
    err_print(int code, t_info *info)
{
    (code == 1) ? ft_printf("Error : Invalid arguments\n\
        Expected command: ./minirt SCENE_FILE.rt [-save]\n") : 0;
    err_close(info);
}

void
    arg_check(int ac, char **av)
{
    int     fd;

    if ((ac != 2 && ac != 3) ||
        (ac == 3 && ft_memcmp(av[2], "-save", 6)) ||
        iswrong_file_format(av[1]))
        err_print(1, NULL);
    fd = open(av[1], O_RDONLY);
}

int
    main(int ac, char **av)
{
    arg_check(ac, av);
    
        t_info  info;

        info.mlx = mlx_init();
        info.win.ptr = mlx_new_window(info.mlx, 1000, 1000, "MiniRT");

        mlx_hook(info.win.ptr, 17, 0, err_close, &info);
        mlx_key_hook(info.win.ptr, &key_hooked, &info);
    mlx_loop(info.win.ptr);
}
