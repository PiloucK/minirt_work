/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing_prints.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 15:48:45 by clkuznie          #+#    #+#             */
/*   Updated: 2020/08/06 15:48:48 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void
    print_infos(t_info *info)
{
    ft_printf("%p\n", info);
    ft_printf("mlx_ptr = %p\n\
    win struct ptr = %p\n\
    t_elem_lst first elem = %p\n\
    do_save = %i\n\
    char *last_read_str = %s\n\n",
    info->mlx,
    info->win,
    info->elems,
    info->last_read_str);
}

void
    print_win_info(t_info *info)
{
    ft_printf("win_ptr = %p\n\
    win x size = %i\n\
    win y size = %i\n\n",
    info->win->ptr,
    info->win->size_x,
    info->win->size_y);
}
