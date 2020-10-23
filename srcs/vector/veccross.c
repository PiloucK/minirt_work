/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   veccross.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 18:16:53 by clkuznie          #+#    #+#             */
/*   Updated: 2020/10/21 11:07:41 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vec3lf
    veccross(const t_vec3lf a, const t_vec3lf b)
{
    t_vec3lf    new_vec;

    new_vec.x = a.y * b.z - a.z * b.y;
    new_vec.y = a.z * b.x - a.x * b.z;
    new_vec.z = a.x * b.y - a.y * b.x;
    return (new_vec);
}
