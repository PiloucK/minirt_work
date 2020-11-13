/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 14:12:20 by clkuznie          #+#    #+#             */
/*   Updated: 2020/11/13 01:05:02 by user42           ###   ########.fr       */
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

# define PI			3.14159265359
# define EPSY		0.00001
# define MAX_BOUNCE	1
# define REDUC		8
# define ROT_SPEED	10
# define TRAN_SPEED	1
# define MAX_DIST	1000000
# define ARR_SIZE	16

typedef enum    e_type
{
	CY = 1,
	PL,
	SP,
	SQ,
	TR,
	C,
	A,
	L,
	R,
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
	double			x;
	double			y;
	int         status;
}				t_res;

typedef struct  s_camera
{
	t_vec3lf      dir;
	t_vec3lf       pos;
	t_vec3lf	upguide;
	t_vec3lf	v_right;
	t_vec3lf	v_up;
	double      fov;
	double      w;
}               t_camera;

typedef struct  s_sphere
{
	t_vec3lf       pos;
	double      r;
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
	double      r;
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
	t_vec3lf	n;
}				t_bounce;

typedef struct	s_ray
{
	t_vec3lf	pos;
	t_vec3lf	dir;
	t_color		color;
	t_bounce	bounce;
}				t_ray;

typedef struct	s_light_list
{
	t_vec3lf	pos;
	double		ratio;
	t_color     color;
	void		*next_light;
}				t_light_list;

typedef struct  s_elem_list
{
	int			id;
	void        *elem_detail;
	void        *next_elem;
}               t_elem_list;

typedef struct	s_various
{
	int			max_bounce;
	double		reduc;
	double		rot_speed;
	int			tran_speed;
	double		max_dist;
	int			rot;
}				t_various;

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
	t_elem_list	*cur_camera;
	t_elem_list	*cur_object;
    t_elem_list *first_elem;
	t_light_list	*cur_light;
	t_light_list	*first_light;
    int         do_save;
	t_various	various;
    char        *last_read_str;
	char		***splited_line;
	char		***splited_value;
	void		*img;
}				t_info;

typedef int	(*t_intersect_fnct)(double *closest, t_ray *ray, void *elem_detail);
typedef void	(*t_change_fnct)(void *elem_detail, int key, t_info *info);
t_intersect_fnct	g_intersect_arr[ARR_SIZE];
t_change_fnct	g_change_arr[ARR_SIZE];

void            ambiant_parse(char ***object_params, t_info *info);
void            arg_reading(int ac, char **av, t_info **info);
void			arrfree(char ***arrtofree);
void			camera_parse(char ***object_params, t_info *info);
t_color			color_parse(char *s, t_info *info);
void			cylinder_parse(char ***object_params, t_info *info);
double			double_parse_inrange(char *value, double min_range, double max_range, t_info *info);
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

void			fill_image(t_info *info);
void			info_free(t_info *info);
void			camera_ray_gen(t_ray *ray, t_info *info, double i, double	 j);
void			ray_bounce(t_ray *ray, t_info *info, t_elem_list *hit_elem, int *i);
void			camera_switch(t_info *info);
int			intersect_cylinder(double *closest, t_ray *ray, void *elem_detail);
int			intersect_nothing(double *closest, t_ray *ray, void *elem_detail);
int		    intersect_plane(double *closest, t_ray *ray, void *elem_detail);
int		    intersect_square(double *closest, t_ray *ray, void *elem_detail);
int		    intersect_sphere(double *closest, t_ray *ray, void *elem_detail);
int		    intersect_triangle(double *closest, t_ray *ray, void *elem_detail);
void			intersect_arr_init();
void		    print_vec3lf(t_vec3lf vec);
t_elem_list		*find_closest(t_ray *ray, t_info *info, double closest, int i);
double		plane_dist(double closest, t_ray *ray, t_vec3lf *plane_normal, t_vec3lf o);
double			util_clamp(double nb, double min, double max);

void			change_arr_init();
t_color			color_mult(t_color color, double ratio);
int				color_add(t_color *color, t_color ratio);
int				color_sub(t_color *color, t_color ratio);

t_vec3lf		rotate(t_vec3lf v, t_camera *camera, int key, t_info *info);
t_vec3lf		translate(t_vec3lf pos, int key, t_info *info);
void			change_nothing(void *elem_detail, int key, t_info *info);
void			change_camera(void *elem_detail, int key, t_info *info);
void			change_plane(void *elem_detail, int key, t_info *info);
void			change_square(void *elem_detail, int key, t_info *info);
void			change_cylinder(void *elem_detail, int key, t_info *info);
void			change_triangle(void *elem_detail, int key, t_info *info);
void			change_sphere(void *elem_detail, int key, t_info *info);
void			change_light(void *elem_detail, int key, t_info *info);
int				mouse_hooked(int button, int x, int y, void *arg);
double			var_scale(double var, int key);
void			light_switch(t_info *info);

#endif
