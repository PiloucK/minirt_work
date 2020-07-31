/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 14:12:20 by clkuznie          #+#    #+#             */
/*   Updated: 2020/07/29 14:12:21 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "libft.h"
# include "key_codes.h"
# include <math.h>
# include <mlx.h>
# include <string.h>
#include <stdbool.h>

typedef void *	t_mlx;

typedef struct	s_win
{
	void		*ptr;
	int			x;
	int			y;
}				t_win;

typedef	struct	s_info
{
	t_mlx		mlx;
	t_win		win;
}				t_info;

void			arg_err_print(int code);

#endif
