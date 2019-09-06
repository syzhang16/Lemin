/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tubes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syzhang <syzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 09:07:51 by acarcena          #+#    #+#             */
/*   Updated: 2019/06/25 01:10:18 by syzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int		valid_tube(char *line)
{
	char	*dash;
	int		pos;

	dash = ft_strchr(line, '-');
	if (!(dash != NULL && dash == ft_strrchr(line, '-')))
		return (INVALID);
	pos = dash - line;
	return (pos);
}

static t_lsroom	*address_room(t_parser *parser, char *line, int ret, int nb)
{
	char		*name;
	int			hash;
	t_lsroom	*room;

	room = NULL;
	if (nb == 1)
		name = ft_strndup(line, ret);
	else
		name = ft_strdup(line + ret + 1);
	if (name == NULL)
		return (NULL);
	hash = hash_value(name);
	room = room_occur(parser->hash_rooms[hash], name);
	free(name);
	return (room);
}

int				get_tube(char *line, t_parser *parser)
{
	int			ret;
	t_lsroom	*first_room;
	t_lsroom	*secnd_room;
	t_lsroom	*tmp;

	if ((ret = valid_tube(line)) == INVALID)
		return (CONTINUE);
	if ((first_room = address_room(parser, line, ret, 1)) == NEXIST)
		return (CONTINUE);
	if ((secnd_room = address_room(parser, line, ret, 2)) == NEXIST)
		return (CONTINUE);
	if (first_room->room == secnd_room->room)
		return (CONTINUE);
	tmp = first_room->room->nei;
	while (tmp)
	{
		if (secnd_room->room == tmp->room)
			return (SUCCESS);
		tmp = tmp->next;
	}
	if (list_room_nwadd(&first_room->room->nei, secnd_room->room) != SUCCESS)
		return (ERROR);
	if (list_room_nwadd(&secnd_room->room->nei, first_room->room) != SUCCESS)
		return (ERROR);
	return (SUCCESS);
}

int				parse_tubes(char **line, t_parser *parser)
{
	int ret;

	while ((ret = get_next_line(0, line, 0)) > 0)
	{
		if (*line[0] != 35 && is_tube(*line) == SUCCESS)
		{
			if ((ret = get_tube(*line, parser)) != SUCCESS)
				return (ret);
		}
		else if (is_comment(*line) == SUCCESS || is_command(*line) == SUCCESS)
		{
			if (list_print(parser, &parser->ls_print, line) != SUCCESS)
				return (ERROR);
			continue ;
		}
		else
			return (CONTINUE);
		if (list_print(parser, &parser->ls_print, line) != SUCCESS)
			return (ERROR);
	}
	return (ret);
}
