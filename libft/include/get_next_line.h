/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarcena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 21:40:23 by acarcena          #+#    #+#             */
/*   Updated: 2019/04/30 22:25:57 by acarcena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <sys/types.h>
# include <sys/uio.h>
# include "libft.h"

# define BUFF_SIZE 50

int		filled_buf(char **search, char **buf, int *val, char **line);
int		set_string(char **line, char *search, char **buf, size_t val);
int		clean_gnl(char **buf);
int		get_next_line(const int fd, char **line, int clean);
void	free_get_next_line(int fd);

#endif
