/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambiant_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 13:44:20 by clkuznie          #+#    #+#             */
/*   Updated: 2020/08/30 02:25:58 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void
    ambiant_parse(char **object_params, t_info *info)
{
    if (util_object_params_count(object_params) != 3)
        err_print(3, info, "Wrong ambiant line format");
    if (info->ambiant)
        err_print(3, info, "Redefinition of 'A'");
    if (!(info->ambiant = malloc(sizeof(t_ambiant))))
        err_print(2, info, NULL);
    // info->ambiant->lum = double_value_parse(object_params[1]);
    // info->ambiant->color = color_parse(object_params[2]);
}