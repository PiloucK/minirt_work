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

int
    arg_err_print(int code)
{
    (code == 1) ? write(2, "Error : No arguments \n\
        Expected command: ./minirt SCENE_FILE.rt [-save]\n", 79) : 0;
    return (-1);
}
