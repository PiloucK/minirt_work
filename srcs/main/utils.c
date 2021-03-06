/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 15:57:56 by clkuznie          #+#    #+#             */
/*   Updated: 2020/11/23 03:14:38 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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

static t_elem_list
	*util_newelem(void *details, int id, t_info *info)
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
	t_elem_list	*current_elem;

	current_elem = util_newelem(details, id, info);
	current_elem->next_elem = info->first_elem;
	info->first_elem = current_elem;
}
