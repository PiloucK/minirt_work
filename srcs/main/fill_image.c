/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 23:28:47 by user42            #+#    #+#             */
/*   Updated: 2020/11/23 07:34:52 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void
	chunk_fill(t_color color, t_info *info, int x, int y)
{
	int				i;
	int				j;
	char			*pixel_address;
	unsigned int	*pixel;

	i = 0;
	while (i < info->various.reduc && x + i < info->res->x)
	{
		j = 0;
		while (j < info->various.reduc && y + j < info->res->y)
		{
			pixel_address = info->image.data +
			((y + j) * info->image.line_len +
			(x + i) * (info->image.bits_per_pixel / 8));
			pixel = (unsigned int *)pixel_address;
			*pixel = color.r * 255;
			*pixel = (*pixel << 8) + color.g * 255;
			*pixel = (*pixel << 8) + color.b * 255;
			j++;
		}
		i++;
	}
}

static t_color
	average_color(t_ray *ray, int x, int y, t_info *info)
{
	t_color			color;
	double			i;
	double			j;

	color.r = 0;
	color.g = 0;
	color.b = 0;
	i = 1.0 / 4.0;
	while (i < 1)
	{
		j = 1.0 / 4.0;
		while (j < 1)
		{
			camera_ray_gen(ray, info, x + i, y + j);
			find_closest(ray, info, info->various.max_dist,
				info->various.max_bounce);
			color = color_add_no_limit(ray->color, color);
			j += 1.0 / 4.0;
		}
		i += 1.0 / 4.0;
	}
	return (color_mult(color, 1.0 / (3.0 * 3.0)));
}

static void
	super_sampling(t_ray *ray, int x, int y, t_info *info)
{
	t_color			color;
	char			*pixel_address;
	unsigned int	*pixel;

	while (x < info->res->x)
	{
		y = 0;
		while (y < info->res->y)
		{
			color = average_color(ray, x, y, info);
			pixel_address = info->image.data +
			(y * info->image.line_len +
			x * (info->image.bits_per_pixel / 8));
			pixel = (unsigned int *)pixel_address;
			*pixel = color.r * 255;
			*pixel = (*pixel << 8) + color.g * 255;
			*pixel = (*pixel << 8) + color.b * 255;
			y++;
		}
		x++;
	}
}

void
	fill_image(t_info *info)
{
	t_ray			ray;
	int				x;
	int				y;

	x = 0;
	if (info->various.reduc < 0)
	{
		super_sampling(&ray, 0, 0, info);
		return ;
	}
	while (x < info->res->x + info->various.reduc - 1)
	{
		y = 0;
		while (y < info->res->y + info->various.reduc - 1)
		{
			camera_ray_gen(&ray, info,
				x + info->various.reduc / 2, y + info->various.reduc / 2);
			find_closest(&ray, info, info->various.max_dist,
				info->various.max_bounce);
			chunk_fill(ray.color, info, x, y);
			y += info->various.reduc;
		}
		x += info->various.reduc;
	}
}
