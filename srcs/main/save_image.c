/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 14:04:37 by user42            #+#    #+#             */
/*   Updated: 2020/11/18 12:08:55 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void
	header_to_buf(char *buf, t_size size)
{
	buf[0] = 'B';
	buf[1] = 'M';
	*(unsigned int *)&buf[2] = size;
	(unsigned int)buf[10] = 54;
	(unsigned int)buf[14] = 40;
	(int)buf[18] = (int)info->res->x;
	(int)buf[22] = (int)info->res->y;
	buf[27] = 1;
	buf[29] = 24;
}

void
	save_image(t_info *info)
{
	char	*buf;
	int		fd;
	t_size	size;

	if (!(fd = open("rt_screenshot.bmp", O_WRONLY | O_CREAT, 0644)))
		err_print(2, info, NULL);
	size = 14 + 50 + 3 * (info->res->x % 4 + info->res->x) * info->res->y;
	if (!(buf = malloc(size)))
		err_print(2, info, NULL);
	ft_bzero(buf, size);
	header_to_buf(buf, size);
}
