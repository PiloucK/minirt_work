/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 08:02:08 by clkuznie          #+#    #+#             */
/*   Updated: 2019/10/21 08:02:44 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void
	ft_putstr_fd(char *s, int fd)
{
	size_t	s_len;

	if (s && fd > 0)
	{
		s_len = ft_strlen(s);
		write(fd, s, s_len);
	}
}
