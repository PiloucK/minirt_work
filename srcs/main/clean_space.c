/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_space.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 13:48:24 by clkuznie          #+#    #+#             */
/*   Updated: 2020/11/11 21:29:23 by user42           ###   ########.fr       */
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

void
    clean_lights(t_light_list *first_light)
{
    if (first_light->next_light)
        clean_lights(first_light->next_light);
    free(first_light);
}

void
    info_free(t_info *info)
{
    if (info->image.img)
        mlx_destroy_image(info->mlx, info->image.img);
    free(info->image.img);
    if (info->win)
        mlx_destroy_window(info->mlx, info->win);
    free(info->mlx);
    free(info->win);
    free(info->res);
    free(info->ambiant);
    if (info->first_elem)
        clean_list(info->first_elem);
    if (info->first_light)
        clean_lights(info->first_light);
    free(info->last_read_str);
    if (info->splited_line)
        arrfree(info->splited_line);
    if (info->splited_value)
        arrfree(info->splited_value);
    free(info);
}
