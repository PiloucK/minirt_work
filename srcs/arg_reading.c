/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_reading.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 15:46:43 by clkuznie          #+#    #+#             */
/*   Updated: 2020/09/09 17:19:40 by clkuznie         ###   ########.fr       */
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
    arg_reading(int ac, char **av, t_info **info)
{
    int     fd;
    int     gnl_ret;

    if ((ac != 2 && ac != 3) ||
        (ac == 3 && ft_memcmp(av[2], "-save", 6)) ||
        is_wrong_file_format(av[1]))
        err_print(1, NULL, NULL);
    if ((fd = open(av[1], O_RDONLY)) < 0)
        err_print(2, NULL, NULL);
    init_infos(ac, info);
    while ((gnl_ret = get_next_line(fd, &(*info)->last_read_str)) == 1)
    {
        if (*(*info)->last_read_str && *(*info)->last_read_str != '#')
            parse_redirect(*info);
        ft_printf("%s\n", (*info)->last_read_str);
        free((*info)->last_read_str);
        (*info)->last_read_str = NULL;
    }
    if (gnl_ret == -1)
        err_print(2, NULL, NULL);
print_infos(*info);
    parsed_check(*info);
    close(fd);
}
