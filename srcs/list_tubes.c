/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_tubes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syzhang <syzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 16:48:08 by acarcena          #+#    #+#             */
/*   Updated: 2019/06/25 00:44:57 by syzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		pop_queue(t_lsroom **lsroom)
{
	t_lsroom *tmp;

	tmp = (*lsroom)->next;
	free(*lsroom);
	*lsroom = NULL;
	*lsroom = tmp;
}

int			push_queue(t_lsroom **lsroom, t_stroom *room)
{
	t_lsroom *new;

	(void)lsroom;
	if (!((new) = (t_lsroom*)malloc(sizeof(t_lsroom))))
		return (ERROR);
	ft_bzero(new, sizeof(t_lsroom));
	new->room = room;
	new->next = *lsroom;
	*lsroom = new;
	return (SUCCESS);
}

int			push_back_queue(t_stroom *room, t_lsroom **tail)
{
	t_lsroom *new;

	if (!((new) = (t_lsroom*)malloc(sizeof(t_lsroom))))
		return (ERROR);
	new->room = room;
	new->next = NULL;
	(*tail)->next = new;
	*tail = new;
	return (SUCCESS);
}

t_lsroom	*find_node(t_lsroom **list, t_stroom *room)
{
	t_lsroom *tmp;
	t_lsroom *previous;

	tmp = *list;
	if (*list == NULL)
		return (NULL);
	while (tmp)
	{
		if ((ft_strequ(tmp->room->name, room->name)))
			return (previous);
		previous = tmp;
		tmp = tmp->next;
	}
	return (NULL);
}
