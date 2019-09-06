/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rooms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syzhang <syzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 02:00:50 by acarcena          #+#    #+#             */
/*   Updated: 2019/06/25 00:56:55 by syzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int	get_room(char *line, t_stroom *room)
{
	int ret;
	int len_name;

	len_name = valid_name(line);
	if (len_name == 0)
		return (INV_NAME);
	ret = valid_coordinates(line + len_name + 1, &room->coord);
	if (ret != SUCCESS)
		return (ret);
	if (!(room->name = ft_strndup(line, len_name)))
		return (ERR_NAME);
	return (SUCCESS);
}

static void	update_status(t_parser *parser, t_status *status, t_lsroom *new)
{
	if (status->start == TO_SET)
	{
		parser->start = new;
		status->start = IS_SET;
	}
	else if (status->end == TO_SET)
	{
		parser->end = new;
		status->end = IS_SET;
	}
}

static int	create_room(char *line, t_parser *parser, t_status *status)
{
	int			ret;
	t_stroom	room;
	t_lsroom	*new_room;
	int			hash;

	ft_bzero(&room, sizeof(t_stroom));
	if ((ret = get_room(line, &room)))
		return (ret);
	hash = hash_value(room.name);
	if (room_occur(parser->hash_rooms[hash], room.name) != NEXIST)
	{
		free_stroom(&room);
		return (ERROR);
	}
	if ((ret = list_room_new(&new_room, room)) != SUCCESS)
		return (ret);
	update_status(parser, status, new_room);
	list_room_add(&parser->hash_rooms[hash], new_room);
	return (SUCCESS);
}

int			parse_rooms(char **line, t_parser *parser)
{
	int ret;

	while ((ret = get_next_line(0, line, 0)) > 0)
	{
		if (*line[0] != 35 && is_room(*line) == SUCCESS)
		{
			if ((ret = create_room(*line, parser, &parser->status)) != SUCCESS)
				return (ret);
		}
		else if (is_command(*line) == SUCCESS || is_comment(*line) == SUCCESS)
		{
			if (parse_command(&parser->status, *line) != SUCCESS)
				return (ERROR);
		}
		else if (is_tube(*line) == SUCCESS)
			return (SUCCESS);
		else
			return (INV_LINE);
		if (list_print(parser, &parser->ls_print, line) != SUCCESS)
			return (ERROR);
	}
	return (ret);
}
