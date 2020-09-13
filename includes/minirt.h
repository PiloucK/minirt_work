/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 14:12:20 by clkuznie          #+#    #+#             */
/*   Updated: 2020/09/12 22:03:16 by clkuznie         ###   ########.fr       */
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


#include <stdio.h>

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

typedef double  t_ratio;

typedef struct  s_pos
{
	double      x;
	double      y;
	double      z;
}               t_pos;

typedef struct	s_color
{
	double      r;
	double      g;
	double      b;
}				t_color;

typedef struct  s_vect
{
	double      xdir;
	double      ydir;
	double      zdir;
}               t_vect;

typedef struct	s_ray
{
	t_pos		pos;
	t_vect		dir;
	int			color;
}				t_ray;

typedef struct  s_ambiant
{
	t_ratio     lum;
	t_color     color;
	int			status;
}               t_ambiant;

typedef struct	s_res
{
	int			x_size;
	int			y_size;
	int         status;
}				t_res;

typedef struct  s_camera
{
	t_vect      dir_vect;
	t_pos       pos;
	double      fov;
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
	t_pos       first_point;
	t_pos       second_point;
	t_pos       third_point;
	t_color     color;
}               t_triangle;

typedef struct  s_elem_list
{
	int			id;
	void        *elem_detail;
	void        *next_elem;
}               t_elem_list;

typedef	struct	s_info
{
	void		*mlx;
	void		*win;
	t_res		*res;
	t_ambiant	*ambiant;
    t_elem_list  *first_elem;
    int         do_save;
    char        *last_read_str;
	char		***splited_line;
	char		***splited_value;
}				t_info;

typedef double	(*t_intersect_fnct)(double closest, t_ray *ray, void *elem_detail);
void            ambiant_parse(char ***object_params, t_info *info);
void            arg_reading(int ac, char **av, t_info **info);
void			arrfree(char ***arrtofree);
void			camera_parse(char ***object_params, t_info *info);
t_color			color_parse(char *s, t_info *info);
void			cylinder_parse(char ***object_params, t_info *info);
double			double_parse_inrange(char *value,
	double min_range, double max_range, t_info *info);
int             err_close(t_info *info);
void            err_print(int code, t_info *info, char *extra_comment);
void            init_infos(int ac, t_info **info);
int		        key_hooked(int key, void *arg);
void			light_parse(char ***object_params, t_info *info);
void            parse_rafl(char ***object_params, t_info *info);
void            parse_redirect(t_info *info);
void            parsed_check(t_info *info);
void			plane_parse(char ***object_params, t_info *info);
t_pos			position_parse(char *object_param, t_info *info);
void            print_infos(t_info *info);
void			screen_scan(t_info *info);
void            resolution_parse(char ***object_params, t_info *info);
void			sphere_parse(char ***object_params, t_info *info);
void			square_parse(char ***object_params, t_info *info);
void			triangle_parse(char ***object_params, t_info *info);
void			util_addelem(t_info *info, void *details, int id);
int             util_object_params_count(char **object_params_str);
t_vect			vector_parse(char *object_param, t_info *info);
void			info_free(t_info *info);

#endif
