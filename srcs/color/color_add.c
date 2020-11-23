/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 23:20:25 by user42            #+#    #+#             */
/*   Updated: 2020/11/23 02:14:32 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int
	color_add(t_color *color, t_color ratio)
{
	color->r = util_clamp(color->r + ratio.r, 0, 1);
	color->g = util_clamp(color->g + ratio.g, 0, 1);
	color->b = util_clamp(color->b + ratio.b, 0, 1);
	return (!((color->r != 1) + (color->g != 1) + (color->b != 1)));
}
