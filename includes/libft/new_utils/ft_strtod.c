/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtod.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 17:58:16 by clkuznie          #+#    #+#             */
/*   Updated: 2020/08/31 20:30:45 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static double
g_powersof10[] = {
	10.,
	100.,
	1.0e4,
	1.0e8,
	1.0e16,
	1.0e32,
	1.0e64,
	1.0e128,
	1.0e256,
};

static int
	mant_size_count(const char *str, int *dotnexp, int *i)
{
	int     mant_size;
	
	*dotnexp = -1;
	mant_size = 0;
	while (1)
	{
		if (!ft_isdigit(str[*i]))
		{
			if ((str[*i] != '.') || (*dotnexp >= 0))
				break ;
			*dotnexp = mant_size;
		}
		++*i;
		mant_size++;
	}
	return (mant_size);
}

static int
	half_max_collect(const char *str, int *mant_size, int *i)
{
	int     frac;
	int     limit;
	char    c;

	frac = 0.0;
	limit = (*mant_size > 9) ? 9 : 0;
	while (*mant_size > limit)
	{
		c = str[*i];
		++*i;
		if (str[*i] == '.')
		{
			c = str[*i];
		++*i;
		}
		frac = 10 * frac + (c - '0');
	}
	return (frac);
}

static int
	no_exp_value(const char *str, int mant_size, int *dotnexp, int *i)
{
	int     frac1;
	int     frac2;
	int     exp_i;
	int     frac_exp;

	exp_i = *i;
	*i -= mant_size;
	if (*dotnexp < 0)
		*dotnexp = mant_size;
	else
		mant_size--;
	frac_exp = *dotnexp - ((mant_size > 18) ? 18 : mant_size);
	mant_size = ((mant_size > 18) ? 18 : mant_size);
	frac1 = half_max_collect(str, &mant_size, i);
	frac2 = half_max_collect(str, &mant_size, i);
	*dotnexp = frac_exp;
	*i = exp_i;
	return ((1.0e9 * frac1) + frac2);
}

static int
	skim_exp(const char *str, int *dotnexp, int i, char **endptr)
{
	int     exp_sign;
	int     exp;
	
	exp_sign = 1;
	exp = 0;
	if (str[i] == 'E' || str[i] == 'e')
	{
		++i;
		if (str[i] == '-' && ++i)
			exp_sign = -1;
		else if (str[i] == '+')
			++i;
		while (ft_isdigit(str[i]))
			exp = exp * 10 + (str[(i)++] - '0');
	}
	if (exp_sign < 0)
		*dotnexp = *dotnexp - exp;
	else
		*dotnexp = *dotnexp + exp;
	if (*endptr)
		*endptr = str + i;
	if (*dotnexp < 0 && (*dotnexp = -*dotnexp))
		return (-1);
	else
		return (1);
}

static double
	power_base_to2(int exp)
{
	double	dexp;
	double	*power;

	dexp = 1.0;
	power = g_powersof10;
	while (exp != 0)
	{
		if (exp & 01)
			dexp *= *power;
		exp >>= 1;
		power++;
	}
	return (dexp);
}

double
	ft_strtod(const char *str, char **endptr)
{
	double  d;
	int     sign;
	int     i;
	int     dotnexp;
	int		mant_size;

	sign = 1;
	i = 0;
	while (ft_iswspace(str[i]))
		i++;
	if (str[i] == '-' && ++i)
		sign = -1;
	else if (str[i] == '+')
		i++;
	mant_size = mant_size_count(str, &dotnexp, &i);
	d = no_exp_value(str, mant_size, &dotnexp, &i);
	i = skim_exp(str, &dotnexp, i, endptr);
	if (i == -1)
		d /= power_base_to2(dotnexp);
	else
		d *= power_base_to2(dotnexp);
	return (d * sign);
}
