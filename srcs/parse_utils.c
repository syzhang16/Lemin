/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarcena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 00:31:44 by acarcena          #+#    #+#             */
/*   Updated: 2019/05/24 00:32:01 by acarcena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

char	is_command(char *line)
{
	if (line[0] == '#' && line[1] == '#')
		return (SUCCESS);
	return (ERROR);
}

char	is_comment(char *line)
{
	if (line[0] == '#' && line[1] != '#')
		return (SUCCESS);
	return (ERROR);
}

char	str_is_digit(char *line, int format)
{
	int index;

	index = 0;
	while (line[index] != 0)
	{
		if (!(line[index] >= 48 && line[index] <= 57) && line[index] != 43)
		{
			if (!(format == COORD && (line[index] == 32
				|| line[index] == 45)))
			{
				return (ERROR);
			}
		}
		index++;
	}
	return (SUCCESS);
}

char	is_room(char *line)
{
	if (ft_strchr(line, ' ') == NULL)
		return (ERROR);
	return (SUCCESS);
}

char	is_tube(char *line)
{
	if (ft_strchr(line, '-') == NULL)
		return (ERROR);
	return (SUCCESS);
}
