/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambiant_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 13:44:20 by clkuznie          #+#    #+#             */
/*   Updated: 2020/08/25 19:25:04 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void
    ambiant_parse(char **object_params, t_info *info)
{
    if (util_object_params_count(object_params) != 3)
        err_print(3, info, "Wrong ambiant line format");
    if (info->ambiant.status)
        err_print(3, info, "Redefinition of 'A'");
    info->ambiant.ratio = double_value_parse(object_params[1]);
    info->ambiant.color = color_parse(object_params[2]);
    info->ambiant.status = 1;
}
