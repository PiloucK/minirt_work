/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 18:35:21 by clkuznie          #+#    #+#             */
/*   Updated: 2020/03/11 19:10:33 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int
	line_save(t_follower *cur_line, char **line, int start)
{
	char	*tmp;
	int		i;
	int		tot_len;

	tot_len = 0;
	tmp = *line;
	while ((*line)[tot_len])
		++tot_len;
	if (!(*line = malloc(sizeof(**line) *
		(tot_len += cur_line->i - start - cur_line->junk) + 1)))
	{
		free(tmp);
		return (-1);
	}
	(*line)[tot_len] = '\0';
	i = -1;
	while (tmp[++i])
		(*line)[i] = tmp[i];
	while (i < tot_len)
		(*line)[i++] = (cur_line->buf)[start++];
	cur_line->junk = 0;
	free(tmp);
	return (1);
}

int
	line_elong(t_follower *cur_line, char **line)
{
	int		i;

	i = cur_line->i;
	while (cur_line->i < cur_line->len)
	{
		if ((cur_line->buf)[cur_line->i] == '\n' && (cur_line->i += 1))
		{
			cur_line->junk += 1;
			break ;
		}
		cur_line->i += 1;
	}
	if ((line_save(cur_line, line, i)) == -1)
		return (-1);
	if ((cur_line->buf)[cur_line->i - 1] == '\n')
		return (1);
	return (0);
}

int
	secure(char **line, t_follower *cur_line)
{
	if (!line || !BUFFER_SIZE)
		return (-1);
	if (!cur_line->doing)
	{
		if (!(*line = malloc(sizeof(**line))))
			return (-1);
		**line = '\0';
	}
	return (1);
}

int
	get_next_line(int fd, char **line)
{
	static t_follower	cur_line;
	int					go_next;

	if (secure(line, &cur_line) == -1)
		return (-1);
	cur_line.doing = 1;
	while (cur_line.i < cur_line.len ||
		(cur_line.len = read(fd, cur_line.buf, BUFFER_SIZE)) > 0)
	{
		if ((go_next = line_elong(&cur_line, line)) == -1)
			return (-1);
		if (go_next == 1)
			break ;
		if ((cur_line.i == cur_line.len) && !(cur_line.len = 0))
			cur_line.i = cur_line.len;
	}
	cur_line.doing = 0;
	if (cur_line.len == -1)
		return (-1);
	if (cur_line.len == 0)
		return (0);
	if ((cur_line.i == cur_line.len) && !(cur_line.len = 0))
		cur_line.i = cur_line.len;
	return (1);
}
