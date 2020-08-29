/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_redirect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 15:47:59 by clkuznie          #+#    #+#             */
/*   Updated: 2020/08/06 15:48:04 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void
    uniforme(char *line)
{
    while (*line)
    {
        if (ft_iswspace(*line))
            *line = ' ';
        line++;
    }
}

static void
    parse_switch(char **object_params, t_info *info)
{
    if (!ft_memcmp(object_params[0], "R", 2))
        resolution_parse(object_params, info);
    else if (!ft_memcmp(object_params[0], "A", 2))
        ambiant_parse(object_params, info);
    else if (!ft_memcmp(object_params[0], "c", 2))
        return ;
    else if (!ft_memcmp(object_params[0], "l", 2))
        return ;
    else if (!ft_memcmp(object_params[0], "sp", 3))
        return ;
    else if (!ft_memcmp(object_params[0], "pl", 3))
        return ;
    else if (!ft_memcmp(object_params[0], "sq", 3))
        return ;
    else if (!ft_memcmp(object_params[0], "cy", 3))
        return ;
    else if (!ft_memcmp(object_params[0], "tr", 3))
        return ;
    else
        err_print(3, info, "RAFL Unknown object type");
}

void
    parse_redirect(t_info *info)
{
    char    **object_params;

    uniforme(info->last_read_str);
    object_params = ft_split(info->last_read_str, ' ');
    if (!object_params)
        err_print(2, info, NULL);
    parse_switch(object_params, info);
    object_params_free(object_params);
}
