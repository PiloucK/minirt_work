/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_sphere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 14:12:06 by user42            #+#    #+#             */
/*   Updated: 2020/11/23 02:16:02 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void
	change_sphere(void *elem_detail, int key, t_info *info)
{
	t_sphere	*sphere;

	sphere = elem_detail;
	if (!info->various.rot)
		sphere->pos = translate(sphere->pos, key, info);
	sphere->r = var_scale(sphere->r, key);
}
