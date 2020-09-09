/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_space.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 13:48:24 by clkuznie          #+#    #+#             */
/*   Updated: 2020/09/09 17:33:10 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void
    arrfree(char ***arrtofree)
{
    int     i;

    i = 0;
    while ((*arrtofree)[i])
        free((*arrtofree)[i++]);
    free(*arrtofree);
    *arrtofree = NULL;
}

void
    info_free(t_info *info)
{
    if (info->splited_value)
        arrfree(info->splited_value);
    if (info->splited_line)
        arrfree(info->splited_line);
    if (info->res)
        free(info->res);
    if (info->ambiant)
        free(info->ambiant);
    if (info->last_read_str)
        free(info->last_read_str);
    // if (info->first_elem)
    //     clean_list(info->first_elem);
    free(info);
}
