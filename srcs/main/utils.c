/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 15:57:56 by clkuznie          #+#    #+#             */
/*   Updated: 2020/11/11 23:17:13 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// double
//     fast_clamp(double nb, double min, double max)
// {
//     int  dif;
//     int  dif_sign;

//     dif = nb - min;
//     dif_sign = dif >> 31;
//     nb = nb - (dif & dif_sign);
//     dif = nb - max;
//     dif_sign = dif >> 31;
//     return (nb + (dif & dif_sign));
// }

double
    util_clamp(double nb, double min, double max)
{
    if (nb < min)
        nb = min;
    if (nb > max)
        nb = max;
    return (nb);
}

int
	util_object_params_count(char **object_params)
{
	int			i;

	i = 0;
	while (object_params[i])
		i++;
	return (i);
}

static t_elem_list *
	util_newelem(void *details, int id, t_info *info)
{
	t_elem_list	*newelem;
	
	if (!(newelem = malloc(sizeof(*newelem))))
		err_print(2, info, NULL);
	newelem->id = id;
	newelem->elem_detail = details;
	newelem->next_elem = NULL;
	return (newelem);
}

void
	util_addelem(t_info *info, void *details, int id)
{
	t_elem_list *current_elem;

	current_elem = info->first_elem;
	while (current_elem)
	{
		if (current_elem->next_elem)
			current_elem = current_elem->next_elem;
		else
			break ;
	}
	if (current_elem)
		current_elem->next_elem = util_newelem(details, id, info);
	else
		info->first_elem = util_newelem(details, id, info);
}
