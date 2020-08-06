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

typedef	struct	s_info
{
	t_mlx		mlx;
	t_win		*win;
    t_elem_lst  *elems;
    int         do_save;
    char        *last_read_str;
}				t_info;

typedef enum    e_type
{
    R,
    A,
    C,
    L,
    SP,
    PL,
    SQ,
    CY,
    TR,
}               t_type;

typedef struct  s_object
{
    char        type;
}               t_object;

typedef struct  s_vect
{
    double      dirx;
    double      diry;
    double      dirz;
}               t_vect;

typedef struct  s_ambiant
{
    t_ratio     lum;
    t_color     color;
}               t_ambiant;

typedef struct  s_camera
{
    t_vect      dir_vect;
    t_pos       pos;
    int         fov;
}               t_camera;

typedef struct  s_light
{
    t_pos       pos;
    t_ratio     lum;
    t_color     color;
}               t_light;

typedef struct  s_sphere
{
    t_pos       pos;
    double      diameter;
    t_color     color;
}               t_sphere;

typedef struct  s_plane
{
    t_pos       pos;
    t_vect      dir_vect;
    t_color     color;
}               t_plane;

typedef struct  s_square
{
    t_pos       pos;
    t_vect      dir_vect;
    double      height;
    t_color     color;
}               t_square;

typedef struct  s_cylinder
{
    t_pos       pos;
    t_vect      dir_vect;
    double      diameter;
    double      height;
    t_color     color;
}               t_cylinder;

typedef struct  s_triangle
{
    t_pos       fp_pos;
    t_pos       sp_pos;
    t_pos       tp_pos;
    t_color     color;
}               t_triangle;

// typedef void    (*t_parse_fnct)(char **splited_str, t_info *info);
void            arg_reading(int ac, char **av, t_info *info);
void            line_redirect(t_info *info);
void            resolution_parse(char **object_params, t_info *info);
int             util_object_params_count(char **object_params_str);
void            object_params_free(char **object_params);
void            parse_rafl(char **object_params, t_info *info);
void            parsed_check(t_info *info);
void            init_infos(int ac, t_info *info);
void            err_print(int code, t_info, char *extra_comment);
int             err_close(t_info *info);
void            print_infos(t_info *info);
void            print_win_info(t_info *info);

#endif
