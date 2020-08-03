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
# include <stdbool.h>
# include <fcntl.h>
# include <errno.h>

typedef void *	t_mlx;

typedef struct	s_win
{
	void		*ptr;
	int			size_x;
	int			size_y;
}				t_win;

typedef struct  s_elem_lst
{
    char        *id;
    int         index;
    void        *elem_detail;
    void        *next_elem;
}               t_elem_lst;

typedef double  t_ratio;

typedef struct  s_pos
{
    double      x;
    double      y;
    double      z;
}               t_pos;

typedef struct	s_color {
	double      r;
	double      g;
	double      b;
}				t_color;

typedef struct  s_light
{
    t_pos       pos;
    t_ratio     lum;
    t_color     color;
}               t_light;


typedef	struct	s_info
{
	t_mlx		mlx;
	t_win		win;
    t_elem_lst  *elems;
    bool        do_save;
    char        *last_read_str;
}				t_info;

void			arg_err_print(int code);

#endif
