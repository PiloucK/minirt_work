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
    init_infos(int ac, t_info **info)
{
    if (!(*info = malloc(sizeof(t_info))))
        err_print(2, *info, NULL);
    (*info)->mlx = mlx_init();
    (*info)->win.ptr = NULL;
    (*info)->win.size_x = 0;
    (*info)->win.size_y = 0;
    (*info)->win.res_status = 0;
    (*info)->win.ambiant_status = 0;
    (*info)->elems = NULL;
    (*info)->do_save = (ac != 3 ? 0 : 1);
    (*info)->last_read_str = NULL;
}
