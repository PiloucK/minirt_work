/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 15:46:24 by clkuznie          #+#    #+#             */
/*   Updated: 2020/11/07 16:24:14 by user42           ###   ########.fr       */
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

void
    do_render(t_info *info)
{
    screen_scan(info);
    printf("virtual screen width %lf\n", info->cur_camera->w);
    printf("up vector\n");
    print_vec3lf(info->cur_camera->v_up);
    printf("forward vector\n");
    print_vec3lf(info->cur_camera->dir);
    printf("right vector\n");
    print_vec3lf(info->cur_camera->v_right);
    mlx_put_image_to_window(info->mlx, info->win, info->image.img, 0, 0);
}

void
    forward_translation(t_info *info)
{
    info->cur_camera->pos = vectranslat(info->cur_camera->pos, info->cur_camera->dir, 1);
    pre_render(info);
    mlx_put_image_to_window(info->mlx, info->win, info->image.img, 0, 0);
}

void
    left_translation(t_info *info)
{
    info->cur_camera->pos = vectranslat(info->cur_camera->pos, info->cur_camera->v_right, 1);
    pre_render(info);
    mlx_put_image_to_window(info->mlx, info->win, info->image.img, 0, 0);
}

void
    backward_translation(t_info *info)
{
    info->cur_camera->pos = vectranslat(info->cur_camera->pos, info->cur_camera->dir, -1);
    pre_render(info);
    mlx_put_image_to_window(info->mlx, info->win, info->image.img, 0, 0);
}

void
    right_translation(t_info *info)
{
    info->cur_camera->pos = vectranslat(info->cur_camera->pos, info->cur_camera->v_right, -1);
    pre_render(info);
    mlx_put_image_to_window(info->mlx, info->win, info->image.img, 0, 0);
}

void
    up_translation(t_info *info)
{
    info->cur_camera->pos = vectranslat(info->cur_camera->pos, info->cur_camera->v_up, 1);
    pre_render(info);
    mlx_put_image_to_window(info->mlx, info->win, info->image.img, 0, 0);
}

void
    down_translation(t_info *info)
{
    info->cur_camera->pos = vectranslat(info->cur_camera->pos, info->cur_camera->v_up, -1);
    pre_render(info);
    mlx_put_image_to_window(info->mlx, info->win, info->image.img, 0, 0);
}

void
    right_rotation(t_info *info)
{
    info->cur_camera->dir = vecnorm(vecsum(vecscale(info->cur_camera->v_right, -0.1), info->cur_camera->dir));
    info->cur_camera->v_right = vecnorm(veccross(info->cur_camera->dir, info->cur_camera->upguide));
    info->cur_camera->v_right.y = vecis(info->cur_camera->v_right, 0, 0, 0)
        + info->cur_camera->v_right.y * !vecis(info->cur_camera->v_right, 0, 0, 0);
    info->cur_camera->v_up = vecnorm(veccross(info->cur_camera->v_right, info->cur_camera->dir));
    pre_render(info);
    mlx_put_image_to_window(info->mlx, info->win, info->image.img, 0, 0);
}

void
    left_rotation(t_info *info)
{
    info->cur_camera->dir = vecnorm(vecsum(vecscale(info->cur_camera->v_right, 0.1), info->cur_camera->dir));
    info->cur_camera->v_right = vecnorm(veccross(info->cur_camera->dir, info->cur_camera->upguide));
    info->cur_camera->v_right.y = vecis(info->cur_camera->v_right, 0, 0, 0)
        + info->cur_camera->v_right.y * !vecis(info->cur_camera->v_right, 0, 0, 0);
    info->cur_camera->v_up = vecnorm(veccross(info->cur_camera->v_right, info->cur_camera->dir));
    pre_render(info);
    mlx_put_image_to_window(info->mlx, info->win, info->image.img, 0, 0);
}

int		key_hooked(int key, void *arg)
{
    ft_printf("key :%i\n", key);
	if (key == 65363)
        camera_switch(arg);
    else if (key == 44)
        forward_translation(arg);
    else if (key == 97)
        left_translation(arg);
    else if (key == 111)
        backward_translation(arg);
    else if (key == 101)
        right_translation(arg);
    else if (key == 65505)
        up_translation(arg);
    else if (key == 65507)
        down_translation(arg);
    else if (key == 32)
        do_render(arg);
    else if (key == 46)
        right_rotation(arg);
    else if (key == 39)
        left_rotation(arg);
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
    pre_render(info);
}

void
    use_window(t_info *info)
{
    info->win = mlx_new_window(info->mlx, info->res->x, info->res->y, "MiniRT");
    mlx_put_image_to_window (info->mlx, info->win, info->image.img, 0, 0);
    mlx_hook(info->win, 17, 0, &err_close, info);
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
