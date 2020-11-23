/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 17:06:02 by clkuznie          #+#    #+#             */
/*   Updated: 2020/11/23 01:49:34 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include <math.h>

typedef struct	s_vec3lf
{
	double		x;
	double		y;
	double		z;
}				t_vec3lf;

double			vecangle(const t_vec3lf a, const t_vec3lf b);
t_vec3lf		veccross(const t_vec3lf a, const t_vec3lf b);
double			vecdot(const t_vec3lf a, const t_vec3lf b);
int				vecis(const t_vec3lf vector, const double x, const double y,
	const double z);
double			vecmag(const t_vec3lf vector);
t_vec3lf		vecmult(const t_vec3lf a, const t_vec3lf b);
t_vec3lf		vecnew(const t_vec3lf origin, const t_vec3lf dest);
t_vec3lf		vecnewvalues(const double x, const double y, const double z);
t_vec3lf		vecnorm(const t_vec3lf vector);
double			vecprod(const t_vec3lf a, const t_vec3lf b, const double angle);
t_vec3lf		vecscale(t_vec3lf vector, const double i);
t_vec3lf		vecsub(const t_vec3lf a, const t_vec3lf b);
t_vec3lf		vecsum(const t_vec3lf a, const t_vec3lf b);
t_vec3lf		vectranslat(const t_vec3lf origin, const t_vec3lf direction,
	const double dist);
t_vec3lf		veczero(void);

#endif
