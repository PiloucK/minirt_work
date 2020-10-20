/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 15:46:24 by clkuznie          #+#    #+#             */
/*   Updated: 2020/10/20 16:23:46 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// t_parse_fnct    parse_array[256];

void
    up_light(t_info *info)
{
    info->cur_light->pos.y -= 10;
    screen_scan(info);
    mlx_put_image_to_window(info->mlx, info->win, info->image.img, 0, 0);
}

void
    left_light(t_info *info)
{
    info->cur_light->pos.x -= 10;
    screen_scan(info);
    mlx_put_image_to_window(info->mlx, info->win, info->image.img, 0, 0);
}

void
    down_light(t_info *info)
{
    info->cur_light->pos.y += 10;
    screen_scan(info);
    mlx_put_image_to_window(info->mlx, info->win, info->image.img, 0, 0);
}

void
    right_light(t_info *info)
{
    info->cur_light->pos.x += 10;
    screen_scan(info);
    mlx_put_image_to_window(info->mlx, info->win, info->image.img, 0, 0);
}

int		key_hooked(int key, void *arg)
{
    ft_printf("key :%i\n", key);
	if (key == 65363)
        camera_switch(arg);
    else if (key == 44)
        up_light(arg);
    else if (key == 97)
        left_light(arg);
    else if (key == 111)
        down_light(arg);
    else if (key == 101)
        right_light(arg);
	else if (key == 65307)
    {
        info_free(arg);
		exit (0);
    }
	return (0);
}

void
    test_render(t_info *info)
{
    t_image     *i;

    i = &info->image;
    i->img = mlx_new_image(info->mlx, info->res->x, info->res->y);
    i->data = mlx_get_data_addr(
        i->img, &i->bits_per_pixel, &i->line_len, &i->endian);
    screen_scan(info);
}

void
    use_window(t_info *info)
{
    info->win = mlx_new_window(info->mlx, info->res->x, info->res->y, "MiniRT");
    mlx_put_image_to_window (info->mlx, info->win, info->image.img, 0, 0);
    mlx_hook(info->win, 17, 0, err_close, info);
    mlx_key_hook(info->win, &key_hooked, info);
    mlx_loop(info->mlx);
}

int
    main(int ac, char **av)
{
    t_info  *info;

    arg_reading(ac, av, &info);
    test_render(info);
    if (!info->do_save)
        use_window(info);
    // render(info);
    info_free(info);
    err_close(NULL);
}
