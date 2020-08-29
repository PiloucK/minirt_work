/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing_prints.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 15:48:45 by clkuznie          #+#    #+#             */
/*   Updated: 2020/08/25 17:01:00 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void
    print_infos(t_info *info)
{
    ft_printf("%p\n", info);
    ft_printf("    mlx_ptr = %p\n\
    win ptr = %p\n\
    win x size = %i\n\
    win y size = %i\n\
    t_elem_lst first elem = %p\n\
    do_save = %i\n\
    char *last_read_str = %s\n",
    info->mlx,
    info->win.ptr,
    info->win.size_x,
    info->win.size_y,
    info->elems,
    info->do_save,
    info->last_read_str);
    ft_printf("side info:\n\
    res status = %i\n\
    ambiant status = %i\n\n",
    info->win.res_status,
    info->ambiant.status);
}
