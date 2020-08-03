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

bool	is_wrong_file_format(char *filename)
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
    (code == 2) ? ft_printf("Error : %s\n", strerror(errno)) : 0;
    err_close(info);
}

void
    init_infos(int ac, t_info *info)
{
    if (!(info = malloc(sizeof(t_info))))
        err_print(2, info);
    info->do_save = (ac == 3 ? true : false);
    // mlx_get_screen_size(info->mlx, &info->win.size_x, &info->win.size_y);
    info->win.size_x = 1920;
    info->win.size_y = 1080;
}

void
    line_parse(t_info *info)
{
    ft_printf("%s\n", info->last_read_str);
}

void
    parsed_check(t_info *info)
{
    (void)info;
}

void
    arg_reading(int ac, char **av, t_info *info)
{
    int     fd;
    int     gnl_ret;

    if ((ac != 2 && ac != 3) ||
        (ac == 3 && ft_memcmp(av[2], "-save", 6)) ||
        is_wrong_file_format(av[1]))
        err_print(1, NULL);
    if ((fd = open(av[1], O_RDONLY)) < 0)
        err_print(2, NULL);
    init_infos(ac, info);
    while ((gnl_ret = get_next_line(fd, &info->last_read_str)) == 1)
    {
        if (*info->last_read_str != '#')
            line_parse(info);
        free(info->last_read_str);
        info->last_read_str = NULL;
    }
    if (gnl_ret == -1)
        err_print(2, NULL);
    parsed_check(info);
    close(fd);
}

int
    main(int ac, char **av)
{
    t_info  info;

    arg_reading(ac, av, &info);
    

        info.mlx = mlx_init();
        info.win.ptr = mlx_new_window(info.mlx, 1000, 1000, "MiniRT");

        mlx_hook(info.win.ptr, 17, 0, err_close, &info);
        mlx_key_hook(info.win.ptr, &key_hooked, &info);
    mlx_loop(info.win.ptr);
}
