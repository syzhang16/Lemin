/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_get_next_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarcena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 22:22:58 by acarcena          #+#    #+#             */
/*   Updated: 2019/04/30 22:24:30 by acarcena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		filled_buf(char **search, char **buf, int *val, char **line)
{
	*search = ft_strchr((const char*)*buf, '\n');
	if (*search)
		*val = *search - *buf;
	if (set_string(line, *search, buf, *val) == -1)
		return (-1);
	if (*search)
		return (1);
	else
		return (0);
}

int		clean_gnl(char **buf)
{
	free(*buf);
	*buf = NULL;
	return (1);
}

void	free_get_next_line(int fd)
{
	char *line;

	line = NULL;
	while (get_next_line(fd, &line, 0) > 0)
	{
		free(line);
		line = NULL;
	}
}
