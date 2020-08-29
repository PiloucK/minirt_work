/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 15:57:56 by clkuznie          #+#    #+#             */
/*   Updated: 2020/08/25 19:27:47 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int
    util_object_params_count(char **object_params)
{
    int     i;

    i = 0;
    while (object_params[i])
        i++;
    return (i);
}
