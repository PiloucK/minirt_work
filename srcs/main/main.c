/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 15:46:24 by clkuznie          #+#    #+#             */
/*   Updated: 2020/11/23 05:07:09 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void
	build_image(t_info *info)
{
	t_image		*i;

	i = &info->image;
	i->img = mlx_new_image(info->mlx, info->res->x, info->res->y);
	i->data = mlx_get_data_addr(
		i->img, &i->bits_per_pixel, &i->line_len, &i->endian);
	if (info->do_save)
		info->various.reduc = -1;
	fill_image(info);
}

int
	update_window(void *param)
{
	t_info		*info;

	info = param;
	mlx_put_image_to_window(info->mlx, info->win, info->image.img, 0, 0);
	return (0);
}

void
	use_window(t_info *info)
{
	info->win = mlx_new_window(info->mlx, info->res->x, info->res->y, "MiniRT");
	mlx_put_image_to_window(info->mlx, info->win, info->image.img, 0, 0);
	mlx_mouse_hook(info->win, mouse_hooked, info);
	mlx_hook(info->win, 17, (1L << 17), err_close, info);
	mlx_hook(info->win, 15, (1L << 16), update_window, info);
	mlx_key_hook(info->win, key_hooked, info);
	mlx_loop(info->mlx);
}

int
	main(int ac, char **av)
{
	t_info		*info;

	arg_reading(ac, av, &info);
	intersect_arr_init();
	build_image(info);
	change_arr_init();
	if (!info->do_save)
		use_window(info);
	else
		save_image(info);
	err_close(info);
}
