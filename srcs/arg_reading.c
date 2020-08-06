/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_reading.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 15:46:43 by clkuznie          #+#    #+#             */
/*   Updated: 2020/08/06 15:46:45 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int
    is_wrong_file_format(char *filename)
{
	int	i;

	i = ft_strlen(filename);
	return (i < 4 ||
            filename[i - 3] != '.' ||
			filename[i - 2] != 'r' ||
			filename[i - 1] != 't');
}

void
    arg_reading(int ac, char **av, t_info *info)
{
    int     fd;
    int     gnl_ret;
    char    *test;

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
    while ((gnl_ret = get_next_line(fd, &test)) == 1)
    {
        info->last_read_str = test;
    print_all_info(info);
        if (*info->last_read_str && *info->last_read_str != '#')
            line_redirect(info);
        free(info->last_read_str);
        info->last_read_str = NULL;
    }
    if (gnl_ret == -1)
        err_print(2, NULL, NULL);
    parsed_check(info);
    close(fd);
}
