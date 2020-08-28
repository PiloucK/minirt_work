/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing_prints.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 15:48:45 by clkuznie          #+#    #+#             */
/*   Updated: 2020/08/28 21:36:25 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void
    print_infos(t_info *info)
{
    ft_printf("%i\n", info->do_save);
    ft_printf("%p\n", info);
    ft_printf("mlx_ptr = %p\n\
    win ptr = %p\n\
    win x size = %i\n\
    win y size = %i\n\
    t_elem_lst first elem = %p\n\
    do_save = %i\n\
    char *last_read_str = %s\n\n",
    info->mlx,
    info->win.ptr,
    info->win.size_x,
    info->win.size_y,
    info->first_elem,
    info->do_save,
    info->last_read_str);
}
