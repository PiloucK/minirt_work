/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_switch.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 00:41:03 by user42            #+#    #+#             */
/*   Updated: 2020/11/23 02:20:40 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void
	light_switch(t_info *info)
{
	t_light_list	*cur_light;

	cur_light = info->first_light;
	if (!info->cur_light)
		return ;
	while (cur_light != info->cur_light)
		cur_light = cur_light->next_light;
	cur_light = cur_light->next_light;
	if (!cur_light)
		cur_light = info->first_light;
	info->various.rot = 2;
	if (cur_light == info->cur_light)
		return ;
	info->cur_light = cur_light;
}
