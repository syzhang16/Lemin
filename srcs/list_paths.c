/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_paths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syzhang <syzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 19:12:31 by acarcena          #+#    #+#             */
/*   Updated: 2019/06/25 00:37:31 by syzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	pop_paths(t_paths **paths)
{
	t_paths *tmp;

	tmp = (*paths)->next;
	free_lsroom_node(&(*paths)->rooms);
	free(*paths);
	*paths = NULL;
	*paths = tmp;
}

int		push_paths(t_solver *solver, t_paths *paths)
{
	t_paths *new;

	if (!((new) = (t_paths*)malloc(sizeof(t_paths))))
		return (ERROR);
	ft_bzero(new, sizeof(t_paths));
	new->next = NULL;
	if (solver->paths == NULL)
	{
		solver->paths = paths;
		solver->tail_paths = paths;
	}
	else
	{
		solver->tail_paths->next = paths;
		solver->tail_paths = paths;
	}
	return (SUCCESS);
}

int		create_paths(t_paths **paths)
{
	t_paths *new;

	if (!((new) = (t_paths*)malloc(sizeof(t_paths))))
		return (ERROR);
	ft_bzero(new, sizeof(t_paths));
	new->next = NULL;
	*paths = new;
	return (SUCCESS);
}
