/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 15:46:24 by clkuznie          #+#    #+#             */
/*   Updated: 2020/11/12 15:51:04 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void
    forward_translation(t_info *info)
{
    info->cur_camera->pos = vectranslat(info->cur_camera->pos, info->cur_camera->dir, 1);
    fill_image(info);
    mlx_put_image_to_window(info->mlx, info->win, info->image.img, 0, 0);
}

void
    left_translation(t_info *info)
{
    info->cur_camera->pos = vectranslat(info->cur_camera->pos, info->cur_camera->v_right, 1);
    fill_image(info);
    mlx_put_image_to_window(info->mlx, info->win, info->image.img, 0, 0);
}

void
    backward_translation(t_info *info)
{
    info->cur_camera->pos = vectranslat(info->cur_camera->pos, info->cur_camera->dir, -1);
    fill_image(info);
    mlx_put_image_to_window(info->mlx, info->win, info->image.img, 0, 0);
}

void
    right_translation(t_info *info)
{
    info->cur_camera->pos = vectranslat(info->cur_camera->pos, info->cur_camera->v_right, -1);
    fill_image(info);
    mlx_put_image_to_window(info->mlx, info->win, info->image.img, 0, 0);
}

void
    up_translation(t_info *info)
{
    info->cur_camera->pos = vectranslat(info->cur_camera->pos, info->cur_camera->v_up, 1);
    fill_image(info);
    mlx_put_image_to_window(info->mlx, info->win, info->image.img, 0, 0);
}

void
    down_translation(t_info *info)
{
    info->cur_camera->pos = vectranslat(info->cur_camera->pos, info->cur_camera->v_up, -1);
    fill_image(info);
    mlx_put_image_to_window(info->mlx, info->win, info->image.img, 0, 0);
}

void
    right_rotation(t_info *info)
{
    t_vec3lf    tmp;

    tmp = vecnorm(veccross(info->cur_camera->dir, info->cur_camera->v_up));
    info->cur_camera->dir = vecnorm(vecsum(vecscale(info->cur_camera->dir, cos(10 * (PI / 180))), vecscale(tmp, sin(10 * (PI / 180)))));
    tmp = vecnorm(veccross(info->cur_camera->v_right, info->cur_camera->v_up));
    info->cur_camera->v_right = vecnorm(vecsum(vecscale(info->cur_camera->v_right, cos(10 * (PI / 180))), vecscale(tmp, sin(10 * (PI / 180)))));
    info->cur_camera->v_up = vecscale(vecnorm(veccross(info->cur_camera->v_right, info->cur_camera->dir)), -1);
    fill_image(info);
    mlx_put_image_to_window(info->mlx, info->win, info->image.img, 0, 0);
}

void
    left_rotation(t_info *info)
{
    t_vec3lf    tmp;

    tmp = vecnorm(veccross(info->cur_camera->dir, info->cur_camera->v_up));
    info->cur_camera->dir = vecnorm(vecsum(vecscale(info->cur_camera->dir, cos(350 * (PI / 180))), vecscale(tmp, sin(350 * (PI / 180)))));
    tmp = vecnorm(veccross(info->cur_camera->v_right, info->cur_camera->v_up));
    info->cur_camera->v_right = vecnorm(vecsum(vecscale(info->cur_camera->v_right, cos(350 * (PI / 180))), vecscale(tmp, sin(350 * (PI / 180)))));
    info->cur_camera->v_up = vecscale(vecnorm(veccross(info->cur_camera->v_right, info->cur_camera->dir)), -1);
    fill_image(info);
    mlx_put_image_to_window(info->mlx, info->win, info->image.img, 0, 0);
}

int		key_hooked(int key, void *arg)
{
    t_elem_list     *cur_object;
    
    cur_object = ((t_info *)arg)->cur_object;
    ft_printf("key :%i\n", key);
	if (key == 65363)
        camera_switch(arg);
    if (key == 44 || key == 111 || key == 97
        || key == 101)
        (*g_movement_arr[cur_object->id])(cur_object->elem_detail, key);
    else if (key == 112)
        ((t_info *)arg)->various.rot = !((t_info *)arg)->various.rot;
        // forward_translation(arg);
    // else if (key == 111)
    //     backward_translation(arg);
    // else if (key == 97)
    //     left_translation(arg);
    // else if (key == 101)
    //     right_translation(arg);
    // else if (key == 65505)
    //     up_translation(arg);
    // else if (key == 65507)
    //     down_translation(arg);
    // else if (key == 39)
    //     left_rotation(arg);
    // else if (key == 46)
        // right_rotation(arg);
    else if (key == 32)
    {
        ((t_info *)arg)->various.reduc = 1;
        fill_image(arg);
        mlx_put_image_to_window(info->mlx, info->win, info->image.img, 0, 0);
        ((t_info *)arg)->various.reduc = REDUC;
    }
	else if (key == 65307)
    {
        info_free(arg);
		exit (0);
    }
	return (0);
}

void
    build_image(t_info *info)
{
    t_image     *i;

    i = &info->image;
    i->img = mlx_new_image(info->mlx, info->res->x, info->res->y);
    i->data = mlx_get_data_addr(
        i->img, &i->bits_per_pixel, &i->line_len, &i->endian);
    fill_image(info);
}

void
    use_window(t_info *info)
{
    info->win = mlx_new_window(info->mlx, info->res->x, info->res->y, "MiniRT");
    mlx_put_image_to_window (info->mlx, info->win, info->image.img, 0, 0);
    // mlx_hook(info->win, 17, 0, &err_close, info);
    mlx_key_hook(info->win, &key_hooked, info);
    mlx_loop(info->mlx);
}

int
    main(int ac, char **av)
{
    t_info  *info;

    arg_reading(ac, av, &info);
    build_image(info);
    printf("toto\n");
    if (!info->do_save)
        use_window(info);
    info_free(info);
    err_close(NULL);
}
