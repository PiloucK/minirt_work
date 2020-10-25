/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 18:22:51 by clkuznie          #+#    #+#             */
/*   Updated: 2020/10/25 17:26:55 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void
    light_parse(char ***object_params, t_info *info)
{
    t_light    *details;
    
    if (util_object_params_count(*object_params) != 4)
		err_print(3, info, "Wrong light line format");
    if (!(details = malloc(sizeof(*details))))
        err_print(2, info, NULL);
    details->pos = position_parse((*object_params)[1], info);
    details->ratio = double_parse_inrange((*object_params)[2], 0.0, 1.0, info);
    details->color = color_parse((*object_params)[3], info);
    info->cur_light = details;
    util_addelem(info, details, L);
}
