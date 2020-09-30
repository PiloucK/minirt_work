/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_space.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 13:48:24 by clkuznie          #+#    #+#             */
/*   Updated: 2020/09/30 22:58:31 by clkuznie         ###   ########.fr       */
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
    free(first_elem->elem_detail);
    if (first_elem->next_elem)
        clean_list(tmp);
    free(first_elem);
}

//  To check: cur_camera free
void
    info_free(t_info *info)
{
    free(info->mlx);
    free(info->win);
    free(info->res);
    free(info->ambiant);
    if (info->first_elem)
        clean_list(info->first_elem);
    free(info->last_read_str);
    if (info->splited_line)
        arrfree(info->splited_line);
    if (info->splited_value)
        arrfree(info->splited_value);
    free(info);
}
