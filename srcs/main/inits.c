/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 16:00:25 by clkuznie          #+#    #+#             */
/*   Updated: 2020/10/08 15:37:38 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void
    init_infos(int ac, t_info **info)
{
    if (!(*info = malloc(sizeof(t_info))))
        err_print(2, *info, NULL);
    (*info)->mlx = mlx_init();
    (*info)->win = NULL;
    (*info)->res = NULL;
    (*info)->ambiant = NULL;
    (*info)->cur_camera = NULL;
    (*info)->first_elem = NULL;
    (*info)->do_save = (ac != 3 ? 0 : 1);
    (*info)->last_read_str = NULL;
    (*info)->splited_line = NULL;
    (*info)->splited_value = NULL;
}