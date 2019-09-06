/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarcena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 04:47:12 by acarcena          #+#    #+#             */
/*   Updated: 2019/07/03 04:47:23 by acarcena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

void	reset_hash(t_parser *lparser)
{
	int			i;
	t_lsroom	*tmp;

	i = 0;
	while (i < HASH_SIZE)
	{
		if (lparser->hash_rooms[i])
		{
			tmp = lparser->hash_rooms[i];
			while (tmp)
			{
				tmp->room->parent = NULL;
				tmp->room->visited = 0;
				tmp = tmp->next;
			}
		}
		i++;
	}
}

void	get_children(t_parser *parser)
{
	t_stroom *cur;

	cur = parser->end->room;
	while (cur != parser->start->room)
	{
		if (cur->child == cur->parent)
			cur->child = NULL;
		else
			cur->father = cur->parent;
		if (cur->parent->father == cur)
			cur->father = NULL;
		else
			cur->parent->child = cur;
		cur = cur->parent;
	}
}

int		algorithm(t_parser *parser, t_solver *solver)
{
	t_clust *clust;

	clust = NULL;
	while (bfs(parser))
	{
		get_children(parser);
		if (get_paths(parser, solver) != SUCCESS)
			return (ERROR);
		if (assign_clust(solver, &clust) != SUCCESS)
			return (ERROR);
		number_turns(clust);
		if ((clust->nb_turns < solver->nb_turns || solver->nb_turns == 0)
				&& !check_overlaping(parser, solver->paths)
				&& !check_paths_validity(parser, solver->paths))
		{
			if (solver->nb_turns != 0)
				free_clust(&solver->clust);
			solver->nb_turns = clust->nb_turns;
			solver->clust = clust;
		}
		else if (clust->paths != NULL)
			free_clust(&clust);
	}
	solver->paths = NULL;
	if (solver->clust)
		ft_printf("BEST: %d\n", solver->clust->nb_turns);
	return (SUCCESS);
}
