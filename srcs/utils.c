/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 15:57:56 by clkuznie          #+#    #+#             */
/*   Updated: 2020/08/31 19:37:26 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int
	util_object_params_count(char **object_params)
{
	int			i;

	i = 0;
	while (object_params[i])
		i++;
	return (i);
}

t_elem_list *
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

	if (!info->first_elem)
	{
		info->first_elem = util_newelem(details, id, info);
		return ;
	}
	current_elem = info->first_elem;
	while (current_elem)
	{
		if (current_elem->next_elem)
			current_elem = current_elem->next_elem;
		else
			break ;
	}
	current_elem->next_elem = util_newelem(details, id, info);
}
