/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_triangle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 20:04:50 by user42            #+#    #+#             */
/*   Updated: 2020/11/12 23:20:57 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void
    change_triangle(void *elem_detail, int key, t_info *info)
{
    t_triangle     *triangle;

    triangle = elem_detail;
    if (!info->various.rot)
    {
        triangle->a = translate(triangle->a, key, info);
        triangle->b = translate(triangle->b, key, info);
        triangle->c = translate(triangle->c, key, info);
    }
}
