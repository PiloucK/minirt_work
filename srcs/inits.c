/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 16:00:25 by clkuznie          #+#    #+#             */
/*   Updated: 2020/08/06 16:00:26 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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
