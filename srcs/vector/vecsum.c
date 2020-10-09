/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vecsum.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 18:15:01 by clkuznie          #+#    #+#             */
/*   Updated: 2020/10/09 09:27:24 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vec3lf
    vecsum(const t_vec3lf a, const t_vec3lf b)
{
    t_vec3lf    sum;
    
    sum.x = a.x + b.x;
    sum.y = a.y + b.y;
    sum.z = a.z + b.z;
    return (sum);
}
