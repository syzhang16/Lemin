/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repartition.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarcena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 17:37:34 by acarcena          #+#    #+#             */
/*   Updated: 2019/06/24 17:37:41 by acarcena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	swap(t_lsroom **a, t_lsroom **b)
{
	t_lsroom *tmp;

	tmp = (*a);
	(*a) = (*b);
	(*b) = tmp;
}

static void	swapi(unsigned int *a, unsigned int *b)
{
	unsigned int tmp;

	tmp = (*a);
	(*a) = (*b);
	(*b) = tmp;
}

void		bubble(t_paths *all_paths)
{
	t_paths *tmp;

	tmp = all_paths;
	while (tmp->next)
	{
		if (tmp->len > tmp->next->len)
		{
			swap(&tmp->rooms, &tmp->next->rooms);
			swapi(&tmp->len, &tmp->next->len);
			tmp = all_paths;
		}
		else
			tmp = tmp->next;
	}
}

void		stop_ants(t_clust *clust)
{
	t_paths			*tmp;
	unsigned int	first_turns;

	tmp = clust->paths;
	if (clust->nb_paths == 0)
		return ;
	first_turns = (clust->nb_ants - clust->ants_gone) / clust->nb_paths;
	while (tmp)
	{
		if (tmp->len != clust->biggest)
			tmp->ants_limit = clust->biggest - tmp->len + first_turns;
		else
			tmp->ants_limit = first_turns;
		if (clust->rest > 0)
		{
			tmp->ants_limit += 1;
			clust->rest--;
		}
		tmp = tmp->next;
	}
}

void		number_turns(t_clust *clust)
{
	int		bonus;
	t_paths	*tmp;

	bonus = 0;
	if (clust->nb_paths == 0)
		return ;
	tmp = clust->paths;
	while (tmp)
	{
		clust->ants_gone += (clust->biggest - tmp->len);
		tmp = tmp->next;
	}
	if ((clust->rest = (clust->nb_ants - clust->ants_gone)
		% clust->nb_paths) > 0)
		bonus = 1;
	clust->nb_turns = (clust->nb_ants - clust->ants_gone) / clust->nb_paths;
	clust->nb_turns += clust->biggest - 1 + bonus;
}
