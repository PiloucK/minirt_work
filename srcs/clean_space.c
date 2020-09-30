/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_space.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 13:48:24 by clkuznie          #+#    #+#             */
/*   Updated: 2020/09/29 19:36:45 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void
    arrfree(char ***arrtofree)
{
    int         i;

    i = 0;
    while ((*arrtofree)[i])
        free((*arrtofree)[i++]);
    free(*arrtofree);
    *arrtofree = NULL;
}

void
    clean_list(t_elem_list *first_elem)
{
    t_elem_list *tmp;

    tmp = first_elem->next_elem;
    if (first_elem->elem_detail)
        free(first_elem->elem_detail);
    if (first_elem->next_elem)
        clean_list(tmp);
    free(first_elem);
}

void
    info_free(t_info *info)
{
    if (info->mlx)
        free(info->mlx);
    if (info->res)
        free(info->res);
    if (info->ambiant)
        free(info->ambiant);
    if (info->cur_camera)
        free(info->cur_camera);
    if (info->first_elem)
        clean_list(info->first_elem);
    if (info->last_read_str)
        free(info->last_read_str);
    if (info->splited_line)
        arrfree(info->splited_line);
    if (info->splited_value)
        arrfree(info->splited_value);
    free(info);
}
