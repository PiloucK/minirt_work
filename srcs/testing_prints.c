/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing_prints.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 15:48:45 by clkuznie          #+#    #+#             */
/*   Updated: 2020/09/08 21:41:31 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void
    print_infos(t_info *info)
{
    ft_printf("    mlx_ptr = %p\n\
    win ptr = %p\n\
    win x size = %i\n\
    win y size = %i\n\
    t_elem_lst first elem = %p\n\
    do_save = %i\n\
    char *last_read_str = %s\n",
    info->mlx,
    info->win,
    info->res->x_size,
    info->res->y_size,
    info->first_elem,
    info->do_save,
    info->last_read_str);
    ft_printf("side info:\n\
    res status = %i\n\
    ambiant status = %i\n\n",
    !!info->res,
    !!info->ambiant);
}
