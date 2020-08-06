/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 15:57:56 by clkuznie          #+#    #+#             */
/*   Updated: 2020/08/06 15:57:58 by clkuznie         ###   ########.fr       */
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
