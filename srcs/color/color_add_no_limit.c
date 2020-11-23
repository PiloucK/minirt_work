/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_add_no_limit.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 06:57:14 by user42            #+#    #+#             */
/*   Updated: 2020/11/23 07:04:44 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color
	color_add_no_limit(t_color color1, t_color color2)
{
	color1.r += color2.r;
	color1.g += color2.g;
	color1.b += color2.b;
	return (color1);
}
