/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_light.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 20:04:06 by user42            #+#    #+#             */
/*   Updated: 2020/11/23 02:15:37 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void
	change_light(void *elem_detail, int key, t_info *info)
{
	t_light_list	*light;

	(void)elem_detail;
	light = info->cur_light;
	light->pos = translate(light->pos, key, info);
	light->ratio = var_scale(light->ratio, key);
	light->ratio = util_clamp(light->ratio, 0, 1);
}
