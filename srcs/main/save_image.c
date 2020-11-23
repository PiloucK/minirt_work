/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 14:04:37 by user42            #+#    #+#             */
/*   Updated: 2020/11/23 04:58:38 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void
	header_to_buf(char *buf, size_t size, t_info *info)
{
	*((u_int16_t *)&buf[0x00]) = (u_int16_t)0x4d42;
	*((u_int32_t *)&buf[0x02]) = (u_int32_t)size;
	*((u_int32_t *)&buf[0x0A]) = (u_int32_t)14 + 40;
	*((u_int32_t *)&buf[0x0E]) = (u_int32_t)40;
	*((u_int32_t *)&buf[0x12]) = (u_int32_t)info->res->x;
	*((u_int32_t *)&buf[0x16]) = (u_int32_t)info->res->y;
	*((u_int16_t *)&buf[0x1A]) = (u_int16_t)1;
	*((u_int16_t *)&buf[0x1C]) = (u_int16_t)24;
}

void
	pixels_to_buf(char *buf, t_info *info)
{
	int		i;
	int		x;
	int		y;
	char	*pixel;

	i = 14 + 40;
	y = info->res->y - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < (int)info->res->x)
		{
			pixel = info->image.data + (y * info->image.line_len
				+ x * (info->image.bits_per_pixel / 8));
			buf[i + 2] = pixel[2];
			buf[i + 1] = pixel[1];
			buf[i + 0] = pixel[0];
			i += 3;
			x++;
		}
		y--;
	}
}

void
	save_image(t_info *info)
{
	char	*buf;
	int		fd;
	size_t	size;

	if (!(fd = open("rt_screenshot.bmp", O_WRONLY | O_CREAT, 0644)))
		err_print(2, info, NULL);
	size = 14 + 40 + 3 * info->res->x * info->res->y;
	if (!(buf = malloc(size)))
		err_print(2, info, NULL);
	ft_bzero(buf, size);
	header_to_buf(buf, size, info);
	pixels_to_buf(buf, info);
	if (write(fd, buf, size) < 0)
	{
		free(buf);
		err_print(2, info, NULL);
	}
	if (close(fd))
	{
		free(buf);
		err_print(2, info, NULL);
	}
	free(buf);
}
