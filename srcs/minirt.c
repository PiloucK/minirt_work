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

// t_parse_fnct    parse_array[256];

void
    print_all_info(t_info *info)
{
    ft_printf("%p\n", info);
    ft_printf("mlx_ptr = %p\n\
    win struct ptr = %p\n\
    t_elem_lst first elem = %p\n\
    do_save = %i\n\
    char *last_read_str = %s\n",
    info->mlx,
    info->win,
    info->elems,
    info->last_read_str);
    // ft_printf("mlx_ptr = %p\n\    win struct ptr = %p\n\    t_elem_lst first elem = %p\n\    do_save = %i\n\    char *last_read_str = %s\n\    win_ptr from new window = %p\n\    win x size = %i\n\    win y size = %i\n",    info->mlx,  info->win,  info->elems,   info->last_read_str,   info->win->ptr,   info->win->size_x,info->win->size_y);
}

int		err_close(t_info *info)
{
    if (!info)
        exit(EXIT_FAILURE);
    // mlx_destroy_window(info->mlx, info->win->ptr);
	exit(0);
}

int		key_hooked(int key, void *arg)
{
    ft_printf("key :%i\n", key);
	if (key == KEY_ESC)
		err_close(arg);
	return (0);
}

int 	is_wrong_file_format(char *filename)
{
	int	i;

	i = ft_strlen(filename);
	return (i < 4 ||
            filename[i - 3] != '.' ||
			filename[i - 2] != 'r' ||
			filename[i - 1] != 't');
}

void
    err_print(int code, t_info *info, char *extra_comment)
{
    (code == 1) ? ft_printf("Error : Invalid arguments\n\
        Expected command: ./minirt SCENE_FILE.rt [-save]\n") : 0;
    (code == 2) ? ft_printf("Error : %s\n", strerror(errno)) : 0;
    (code == 3) ? ft_printf("Error : %s\n\
        \"%s\"\n", extra_comment, info->last_read_str) : 0;
    err_close(info);
}

void
    init_infos(int ac, t_info *info)
{
    info->mlx = NULL;
    info->win = NULL;
    info->elems = NULL;
    info->do_save = ac;
    info->last_read_str = NULL;
    print_all_info(info);
}

static void
    uniforme(char *line)
{
    while (*line)
    {
        if (ft_iswspace(*line))
            *line = ' ';
        line++;
    }
}

void
    splited_free(char **splited_str)
{
    int     i;

    i = 0;
    while (splited_str[i])
        free(splited_str[i++]);
    free(splited_str);
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
    parse_rafl(char **splited_str, t_info *info)
{
    (void)splited_str;
    err_print(3, info, "RAFL Unknown object type");
}

int
    splited_count(char **splited_str)
{
    int     i;

    i = 0;
    while (splited_str[i])
        i++;
    return (i);
}

void
    resolution_parse(char **splited_str, t_info *info)
{
    t_win   *tmp;

    if (splited_count(splited_str) != 3)
        err_print(3, info, "Wrong resolution line format");
    // if (!(info->win = malloc(sizeof(t_win))))
    //     err_print(2, info, NULL);
    print_all_info(info);
    if (!(tmp = malloc(sizeof(t_win))))
        err_print(2, info, NULL);
    tmp->size_x = ft_atoi(splited_str[1]);
    tmp->size_y = ft_atoi(splited_str[2]);
    info->win = tmp;
    info->win->size_x = tmp->size_x;
    info->win->size_y = tmp->size_y;
    print_all_info(info);
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

// void
//     parse_array_init()
// {
//     int     i;

//     i = 0;
//     while (i < 256)
//         parse_array[i++] = parse_rafl;
//     parse_array[R] = parse_resolution;
// }

// int
//     type_get(char *input_type)
// {
//     if (!ft_memcmp(input_type, "R", 2))
//         return (R);
//     if (!ft_memcmp(input_type, "A", 2))
//         return (A);
//     if (!ft_memcmp(input_type, "c", 2))
//         return (C);
//     if (!ft_memcmp(input_type, "l", 2))
//         return (L);
//     if (!ft_memcmp(input_type, "sp", 3))
//         return (SP);
//     if (!ft_memcmp(input_type, "pl", 3))
//         return (PL);
//     if (!ft_memcmp(input_type, "sq", 3))
//         return (SQ);
//     if (!ft_memcmp(input_type, "cy", 3))
//         return (CY);
//     if (!ft_memcmp(input_type, "tr", 3))
//         return (TR);
//     return (-1);
// }

void
    parse_switch(char **splited_str, t_info *info)
{
    if (!ft_memcmp(splited_str[0], "R", 2))
        resolution_parse(splited_str, info);
    else if (!ft_memcmp(splited_str[0], "A", 2))
        return ;
    else if (!ft_memcmp(splited_str[0], "c", 2))
        return ;
    else if (!ft_memcmp(splited_str[0], "l", 2))
        return ;
    else if (!ft_memcmp(splited_str[0], "sp", 3))
        return ;
    else if (!ft_memcmp(splited_str[0], "pl", 3))
        return ;
    else if (!ft_memcmp(splited_str[0], "sq", 3))
        return ;
    else if (!ft_memcmp(splited_str[0], "cy", 3))
        return ;
    else if (!ft_memcmp(splited_str[0], "tr", 3))
        return ;
    else
        err_print(3, info, "RAFL Unknown object type");
}

void
    line_parse(t_info *info)
{
    char    **splited_str;

    uniforme(info->last_read_str);
    splited_str = ft_split(info->last_read_str, ' ');
    if (!splited_str)
        err_print(2, info, NULL);
// ft_printf("given type = %i for %s\n", type_get(splited_str[0]), splited_str[0]);
    parse_switch(splited_str, info);
    // (*parse_array[type_get(splited_str[0])])(splited_str, info);
    splited_free(splited_str);
// ft_printf("%s\n", info->last_read_str);
}

void
    arg_reading(int ac, char **av, t_info *info)
{
    int     fd;
    int     gnl_ret;

    if ((ac != 2 && ac != 3) ||
        (ac == 3 && ft_memcmp(av[2], "-save", 6)) ||
        is_wrong_file_format(av[1]))
        err_print(1, NULL, NULL);
    if ((fd = open(av[1], O_RDONLY)) < 0)
        err_print(2, NULL, NULL);
    info->do_save=9;
    init_infos(ac, info);

    ft_printf("toto-------------------------\n");
    print_all_info(info);
    while ((gnl_ret = get_next_line(fd, &(info->last_read_str))) == 1)
    {
    print_all_info(info);
        if (*info->last_read_str && *info->last_read_str != '#')
            line_parse(info);
        free(info->last_read_str);
        info->last_read_str = NULL;
    }
    if (gnl_ret == -1)
        err_print(2, NULL, NULL);
    parsed_check(info);
    close(fd);
}

int
    main(int ac, char **av)
{
    t_info  *info;


    if (!(info = malloc(sizeof(t_info))))
        err_print(2, info, NULL);
    arg_reading(ac, av, info);
}
