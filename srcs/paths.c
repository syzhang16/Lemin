/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarcena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 01:26:47 by acarcena          #+#    #+#             */
/*   Updated: 2019/07/01 01:26:58 by acarcena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int	get_rooms(t_lsroom **list, t_stroom *cur)
{
	int			len;
	t_lsroom	*tail;

	len = 1;
	tail = *list;
	while (cur->child)
	{
		if (lsroom_back(list, cur, &tail) != SUCCESS)
			return (0);
		cur = cur->child;
		len++;
	}
	if (lsroom_back(list, cur, &tail) != SUCCESS)
		return (0);
	return (len);
}

static void	paths_add(t_paths **old, t_paths *new)
{
	new->next = *old;
	*old = new;
}

static int	init_p(t_parser *prs, t_solver *slv, t_paths **all, t_lsroom *nei)
{
	t_paths *paths;

	paths = NULL;
	if (create_paths(&paths) != SUCCESS)
		return (ERROR);
	if (list_room_nwadd(&paths->rooms, prs->start->room) != SUCCESS)
		return (ERROR);
	paths->len = get_rooms(&paths->rooms, nei->room);
	if (paths->len != 0)
	{
		slv->nb_paths++;
		paths_add(all, paths);
		if (slv->biggest < paths->len)
			slv->biggest = paths->len;
	}
	else
		return (ERROR);
	return (SUCCESS);
}

int			get_paths(t_parser *prs, t_solver *solver)
{
	t_lsroom	*nei;
	t_paths		*all_paths;

	solver->nb_paths = 0;
	all_paths = NULL;
	nei = prs->start->room->nei;
	while (nei)
	{
		if (nei->room->father == prs->start->room)
		{
			if (init_p(prs, solver, &all_paths, nei) != SUCCESS)
				return (ERROR);
		}
		nei = nei->next;
	}
	solver->paths = all_paths;
	return (SUCCESS);
}
