/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 09:38:18 by clkuznie          #+#    #+#             */
/*   Updated: 2020/07/30 09:38:20 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void
    arg_err_print(int code)
{
    (code == 1) ? ft_printf("Error : No arguments\n\
        Expected command: ./minirt SCENE_FILE.rt [-save]\n") : 0;
    (code == 2) ? ft_printf("Error : %s\n\
        Expected command: ./minirt SCENE_FILE.rt [-save]\n", strerror(E2BIG)) : 0;
    exit(EXIT_FAILURE);
}
