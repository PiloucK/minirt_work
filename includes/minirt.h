/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 14:12:20 by clkuznie          #+#    #+#             */
/*   Updated: 2020/11/08 21:36:56 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "libft.h"
# include "key_codes.h"
# include "vector.h"
# include <math.h>
# include <mlx.h>
# include <string.h>
# include <fcntl.h>
# include <errno.h>
											#include <stdlib.h>
											#include <stdio.h>

# define PI 3.14159265359
# define MAX_DEPTH 1
# define REDUC 8

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

typedef struct	s_color
{
	double      r;
	double      g;
	double      b;
}				t_color;

typedef struct  s_ambiant
{
	double		ratio;
	t_color     color;
	int			status;
}               t_ambiant;

typedef struct	s_res
{
	int			x;
	int			y;
	int         status;
}				t_res;

typedef struct  s_camera
{
	t_vec3lf      dir;
	t_vec3lf       pos;
	t_vec3lf	upguide;
	t_vec3lf	v_right;
	t_vec3lf	v_up;
	double      w;
}               t_camera;

typedef struct  s_light
{
	t_vec3lf       pos;
	double		ratio;
	t_color     color;
}               t_light;

typedef struct  s_sphere
{
	t_vec3lf       pos;
	double      diameter;
	t_color     color;
}               t_sphere;

typedef struct  s_plane
{
	t_vec3lf       pos;
	t_vec3lf      dir;
	t_color     color;
}               t_plane;

typedef struct  s_square
{
	t_vec3lf       pos;
	t_vec3lf      dir;
	double      height;
	t_color     color;
}               t_square;

typedef struct  s_cylinder
{
	t_vec3lf    pos;
	t_vec3lf    dir;
	double      diameter;
	double      height;
	t_color     color;
}               t_cylinder;

typedef struct  s_triangle
{
	t_vec3lf    a;
	t_vec3lf    b;
	t_vec3lf	c;
	t_color     color;
	t_vec3lf	normal;
}               t_triangle;

typedef struct	s_bounce
{
	t_vec3lf	pos;
	t_vec3lf	surface_normal;
}				t_bounce;

typedef struct	s_ray
{
	t_vec3lf	pos;
	t_vec3lf	dir;
	t_color		color;
	t_bounce	bounce;
}				t_ray;

typedef struct  s_elem_list
{
	int			id;
	void        *elem_detail;
	void        *next_elem;
}               t_elem_list;

typedef struct	s_image
{
	void		*img;
	int			bits_per_pixel;
	int			line_len;
	int			endian;
	char		*data;
}				t_image;

typedef	struct	s_info
{
	void		*mlx;
	void		*win;
	t_image		image;
	t_res		*res;
	t_ambiant	*ambiant;
	t_camera	*cur_camera;
	t_light		*cur_light;
    t_elem_list *first_elem;
    int         do_save;
    char        *last_read_str;
	char		***splited_line;
	char		***splited_value;
	void		*img;
}				t_info;

typedef double	(*t_intersect_fnct)(double *closest, t_ray *ray, void *elem_detail);

t_intersect_fnct    intersect_arr[256];

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
void			plane_parse(char ***object_params, t_info *info);
t_vec3lf			position_parse(char *object_param, t_info *info);
void            print_infos(t_info *info);
void			screen_scan(t_info *info);
void			test_scan(t_info *info);
void            resolution_parse(char ***object_params, t_info *info);
void			sphere_parse(char ***object_params, t_info *info);
void			square_parse(char ***object_params, t_info *info);
void			triangle_parse(char ***object_params, t_info *info);
double			util_absvalue(double lf);
void			util_addelem(t_info *info, void *details, int id);
int             util_object_params_count(char **object_params_str);
t_vec3lf			vector_parse(char *object_param, t_info *info);


void			pre_render(t_info *info);
void			info_free(t_info *info);
void			camera_ray_gen(t_ray *ray, t_info *info, double i, double	 j);
void			ray_bounce(t_ray *ray, t_info *info, t_elem_list *hit_elem, int *i);
void			camera_switch(t_info *info);
double			intersect_cylinder(double *closest, t_ray *ray, void *elem_detail);
double			intersect_ntdh(double *closest, t_ray *ray, void *elem_detail);
double		    intersect_plane(double *closest, t_ray *ray, void *elem_detail);
double		    intersect_sphere(double *closest, t_ray *ray, void *elem_detail);
double		    intersect_triangle(double *closest, t_ray *ray, void *elem_detail);
void			intersect_arr_init();
void		    print_vec3lf(t_vec3lf vec);
int		    find_closest(t_ray *ray, t_info *info, double closest, int i);
double		plane_dist(double closest, t_ray *ray, t_vec3lf *plane_normal);


#endif
