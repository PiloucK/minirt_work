/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing_prints.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 15:48:45 by clkuznie          #+#    #+#             */
/*   Updated: 2020/10/06 12:18:51 by clkuznie         ###   ########.fr       */
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
    info->res->x,
    info->res->y,
    info->first_elem,
    info->do_save,
    info->last_read_str);
    ft_printf("side info:\n\
    res status = %i\n\
    ambiant status = %i\n\n",
    !!info->res,
    !!info->ambiant);
}

void
    print_vec3lf(t_vec3lf vec)
{
    printf("%lf | %lf | %lf\n", vec.x, vec.y, vec.z);
    printf("%lf\n", vecmag(&(vec)));
}
