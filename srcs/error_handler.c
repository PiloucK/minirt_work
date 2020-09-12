/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 15:45:46 by clkuznie          #+#    #+#             */
/*   Updated: 2020/09/12 20:57:04 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		err_close(t_info *info)
{
    // if (info)
    //     exit(EXIT_FAILURE);
    // mlx_destroy_window(info->mlx, info->win);
(void)info;
	exit (0);
}

void
    err_print(int code, t_info *info, char *extra_comment)
{
    (code == 1) ? ft_printf("Error : Invalid arguments\n\
        Expected command: ./minirt SCENE_FILE.rt [-save]\n") : 0;
    (code == 2) ? ft_printf("Error : %s\n", strerror(errno)) : 0;
    (code == 3) ? ft_printf("Error : %s\n\
        \"%s\"\n", extra_comment, info->last_read_str) : 0;
    (code == 4) ? ft_printf("Error : %s\n", extra_comment);
    if (info)
        info_free(info);
    err_close(info);
}
