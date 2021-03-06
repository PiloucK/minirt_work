/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution_parse.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 15:45:29 by clkuznie          #+#    #+#             */
/*   Updated: 2020/11/23 04:48:47 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int
	is_full_digits(char *object_param)
{
	int		i;

	i = 0;
	while (ft_isdigit(object_param[i]))
		i++;
	return (!object_param[i]);
}

static void
	resize(t_info *info)
{
	int		display_x;
	int		display_y;

	mlx_get_screen_size(info->mlx, &display_x, &display_y);
	if (display_x < info->res->x)
		info->res->x = display_x;
	if (display_x < info->res->y)
		info->res->y = display_y;
	if (info->res->x * info->res->y < 10000)
		info->various.reduc = 1;
}

void
	resolution_parse(char ***object_params, t_info *info)
{
	if (util_object_params_count(*object_params) != 3)
		err_print(3, info, "Wrong resolution line format");
	if (info->res)
		err_print(3, info, "Redefinition of 'R'");
	if (!is_full_digits((*object_params)[1])
		|| !is_full_digits((*object_params)[2]))
		err_print(3, info, "Only digits are allowed");
	if (!(info->res = malloc(sizeof(t_res))))
		err_print(2, info, NULL);
	info->res->x = double_parse_inrange((*object_params)[1], 0, 0, info);
	info->res->y = double_parse_inrange((*object_params)[2], 0, 0, info);
	resize(info);
	if (info->res->x <= 0 || info->res->y <= 0)
		err_print(3, info, "Can't use suggested size");
}
