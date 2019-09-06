/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarcena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 21:40:31 by acarcena          #+#    #+#             */
/*   Updated: 2018/03/25 22:08:02 by acarcena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	handle_buf(char **buffer, char **buf)
{
	if (!*buf)
		*buf = ft_strdup(*buffer);
	else
		*buf = ft_strjoin_free((CSTCH**)buf, (CSTCH**)buffer, 1);
}

static int	search_buffer(char **buf, CSTIN fd, int *ret, char **srch)
{
	char	*buffer;
	size_t	val;

	val = 0;
	if (!(buffer = (char*)ft_memalloc(sizeof(char) * (BUFF_SIZE + 1))))
		return (-1);
	while (!(*srch = ft_strchr(*buf, '\n')))
	{
		if ((*ret = read(fd, buffer, BUFF_SIZE)) < 1 || buffer[0] == 0)
		{
			free(buffer);
			return (-1);
		}
		buffer[*ret] = '\0';
		handle_buf(&buffer, buf);
		if (*buf == NULL)
		{
			free(buffer);
			return (-1);
		}
		val = ft_strlen(*buf);
	}
	free(buffer);
	return (*srch ? (*srch - *buf) : val);
}

static int	put_string(char **buf, size_t val)
{
	char	*tmp;

	tmp = *buf;
	if ((*buf = ft_strdup((const char*)tmp + (val + 1))) == NULL)
	{
		free(tmp);
		return (-1);
	}
	free(tmp);
	return (1);
}

int			set_string(char **line, char *search, char **buf, size_t val)
{
	size_t	len;

	if (!search)
		val = ft_strlen(*buf);
	if (*line == NULL)
		*line = ft_strndup(*buf, val);
	else
		*line = ft_strnjoin_free((CSTCH**)line, (CSTCH**)buf, val, 1);
	if (*line == NULL)
		return (-1);
	len = ft_strlen(*buf);
	if (len == val || len == val + 1)
	{
		free(*buf);
		*buf = NULL;
	}
	else
	{
		if (put_string(buf, val) != 1)
			return (ERROR);
	}
	return (0);
}

int			get_next_line(const int fd, char **line, int clean)
{
	int				ret;
	static char		*buf = NULL;
	char			*search;
	int				value;

	search = NULL;
	value = 0;
	if (line == NULL)
		return (-1);
	*line = NULL;
	if (clean == 1 && clean_gnl(&buf))
		return (1);
	if (buf != NULL)
		if ((ret = filled_buf(&search, &buf, &value, line)) != 0)
			return (ret == 1 ? 1 : 0);
	value = search_buffer(&buf, fd, &ret, &search);
	if (buf == NULL && *line == NULL)
		ret = 0;
	if (ret == -1 || (ret == 0 && buf == NULL && *line == NULL))
		return (ret);
	if (set_string(line, search, &buf, value) == -1)
		return (-1);
	return (1);
}
