/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_hash.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarcena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 19:38:00 by acarcena          #+#    #+#             */
/*   Updated: 2019/06/24 19:38:09 by acarcena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		free_lsroom_node(t_lsroom **lsroom)
{
	t_lsroom *tmp;

	while (*lsroom)
	{
		tmp = (*lsroom)->next;
		free(*lsroom);
		*lsroom = NULL;
		*lsroom = tmp;
	}
}

void		free_stroom(t_stroom *room)
{
	free(room->name);
	room->name = NULL;
	free_lsroom_node(&room->nei);
}

void		free_lsroom_hash(t_lsroom **lsroom)
{
	t_lsroom *tmp;

	while (*lsroom)
	{
		free_stroom((*lsroom)->room);
		free((*lsroom)->room);
		tmp = (*lsroom)->next;
		free(*lsroom);
		*lsroom = tmp;
	}
}

void		free_hashtable(t_lsroom **hash_rooms)
{
	int index;

	index = 0;
	while (index < HASH_SIZE)
	{
		if (hash_rooms[index] != NULL)
			free_lsroom_hash(&hash_rooms[index]);
		index++;
	}
	free(hash_rooms);
	hash_rooms = NULL;
}
