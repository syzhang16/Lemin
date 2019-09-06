/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_room.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syzhang <syzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 01:04:30 by acarcena          #+#    #+#             */
/*   Updated: 2019/06/25 00:43:12 by syzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int			list_room_new(t_lsroom **room_node, t_stroom room_content)
{
	if (!((*room_node) = (t_lsroom*)malloc(sizeof(t_lsroom))))
		return (LST_ND);
	ft_bzero(*room_node, sizeof(t_lsroom));
	if (!((*room_node)->room = (t_stroom*)malloc(sizeof(t_stroom))))
		return (LST_ST);
	ft_bzero((*room_node)->room, sizeof(t_stroom));
	(*room_node)->room->name = room_content.name;
	(*room_node)->room->coord = room_content.coord;
	(*room_node)->next = NULL;
	return (SUCCESS);
}

void		list_room_add(t_lsroom **list, t_lsroom *new_room)
{
	new_room->next = *list;
	*list = new_room;
}

int			lsroom_back(t_lsroom **list, t_stroom *room, t_lsroom **tail)
{
	t_lsroom *new;

	if (!((new) = (t_lsroom*)malloc(sizeof(t_lsroom))))
		return (ERROR);
	ft_bzero(new, sizeof(t_lsroom));
	new->room = room;
	new->next = NULL;
	if (*list == NULL)
	{
		*list = new;
		*tail = new;
	}
	else
	{
		(*tail)->next = new;
		*tail = new;
	}
	return (SUCCESS);
}

void		list_room_delnode(t_lsroom **list, t_stroom *room)
{
	t_lsroom *tmp;
	t_lsroom *previous;

	tmp = *list;
	previous = NULL;
	if (*list == NULL)
		return ;
	while (tmp)
	{
		if ((ft_strequ(tmp->room->name, room->name)))
		{
			if (previous != NULL)
				previous->next = tmp->next;
			else
				*list = tmp->next;
			free(tmp);
			tmp = NULL;
			return ;
		}
		previous = tmp;
		tmp = tmp->next;
	}
}

int			list_room_nwadd(t_lsroom **list, t_stroom *room)
{
	t_lsroom *new_node;

	if (!((new_node) = (t_lsroom*)malloc(sizeof(t_lsroom))))
		return (LST_ND);
	ft_bzero(new_node, sizeof(t_lsroom));
	new_node->room = room;
	new_node->next = *list;
	*list = new_node;
	return (SUCCESS);
}
