/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 17:06:02 by clkuznie          #+#    #+#             */
/*   Updated: 2020/10/09 09:30:20 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include <math.h>

typedef struct  s_vec3lf
{
    double      x;
    double      y;
    double      z;
}               t_vec3lf;

double          vecangle(const t_vec3lf a, const t_vec3lf b);
double          vecdotprod(const t_vec3lf a, const t_vec3lf b);
double          vecmag(const t_vec3lf vector);
t_vec3lf        vecnew(const t_vec3lf origin, const t_vec3lf dest);
t_vec3lf        vecnorm(const t_vec3lf vector);
double          vecprod(const t_vec3lf a, const t_vec3lf b,
    const double angle);
t_vec3lf        vecsub(const t_vec3lf a, const t_vec3lf b);
t_vec3lf        vecsum(const t_vec3lf a, const t_vec3lf b);
t_vec3lf        vectranslat(const t_vec3lf origin, const t_vec3lf direction, const double dist);
t_vec3lf        veczero(void);

#endif
