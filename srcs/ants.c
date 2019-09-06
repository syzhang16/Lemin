/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarcena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 03:47:23 by acarcena          #+#    #+#             */
/*   Updated: 2019/06/29 14:32:50 by acarcena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	print_ant(t_lsroom *room, int *next_value)
{
	int tmp_ant;

	ft_printf("L%d-%s ", *next_value, room->room->name);
	if (room->room->ant == 0)
	{
		room->room->ant = *next_value;
		*next_value = 0;
	}
	else
	{
		tmp_ant = room->room->ant;
		room->room->ant = *next_value;
		*next_value = tmp_ant;
	}
}

static void	move_ants(t_paths *paths)
{
	int			next_value;
	t_lsroom	*tmp_room;

	tmp_room = paths->rooms;
	next_value = 0;
	while (tmp_room)
	{
		if (tmp_room->room->ant != 0 && next_value == 0)
		{
			next_value = tmp_room->room->ant;
			tmp_room->room->ant = 0;
		}
		else if (next_value != 0)
			print_ant(tmp_room, &next_value);
		tmp_room = tmp_room->next;
	}
}

void		travel_start_end(t_parser *parser, t_stroom *end)
{
	unsigned int nb_ants;

	nb_ants = 1;
	while (nb_ants <= parser->nb_ants)
	{
		if (nb_ants < parser->nb_ants)
			ft_printf("L%d-%s ", nb_ants, end->name);
		else
			ft_printf("L%d-%s\n", nb_ants, end->name);
		nb_ants++;
	}
}

void		travel_ants(t_clust *clust)
{
	unsigned int	nb_fourmis;
	unsigned int	nb_turns;
	t_paths			*tmp;

	nb_turns = 0;
	nb_fourmis = 1;
	if (clust->paths == NULL)
		return ;
	while (nb_turns < clust->nb_turns)
	{
		tmp = clust->paths;
		while (tmp != NULL)
		{
			if (tmp->ants_limit != 0)
			{
				tmp->rooms->room->ant = nb_fourmis;
				nb_fourmis++;
				tmp->ants_limit--;
			}
			move_ants(tmp);
			tmp = tmp->next;
		}
		ft_printf("\n");
		nb_turns++;
	}
}
