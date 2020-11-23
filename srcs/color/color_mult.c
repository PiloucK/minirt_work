/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_mult.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 23:18:26 by user42            #+#    #+#             */
/*   Updated: 2020/11/23 02:14:37 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color
	color_mult(t_color color, double ratio)
{
	color.r *= ratio;
	color.g *= ratio;
	color.b *= ratio;
	return (color);
}
