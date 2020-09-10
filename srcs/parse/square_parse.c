/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 20:04:44 by clkuznie          #+#    #+#             */
/*   Updated: 2020/09/10 20:09:46 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void
    square_parse(char ***object_params, t_info *info)
{
    t_square    *details;
    
    if (util_object_params_count(*object_params) != 5)
		err_print(3, info, "Wrong square line format");
    if (!(details = malloc(sizeof(*details))))
        err_print(2, info, NULL);
    details->pos = position_parse((*object_params)[1], info);
    details->dir_vect = vector_parse((*object_params)[2], info);
    details->height = double_parse_inrange((*object_params)[3], 0, 0, info);
    details->color = color_parse((*object_params)[4], info);
    util_addelem(info, details, SQ);
}
