/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarcena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 05:03:43 by acarcena          #+#    #+#             */
/*   Updated: 2019/05/24 05:03:45 by acarcena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	print_hash_rooms(t_lsroom *ls, int *nb_coll)
{
	int			collision;
	t_lsroom	*tmp2;

	collision = 0;
	while (ls != NULL)
	{
		ft_printf("%10d   %25s  ( %12d / %-12d )     ", collision,
			ls->room->name, ls->room->coord.x, ls->room->coord.y);
		tmp2 = ls->room->nei;
		while (tmp2 != NULL)
		{
			ft_printf("%s ", tmp2->room->name);
			tmp2 = tmp2->next;
		}
		ft_printf("\n");
		ls = ls->next;
		collision++;
	}
	if (collision > 1)
	{
		ft_printf("\033[033;1mNumber of collision: %d\033[0m\n", collision);
		*nb_coll += collision;
	}
}

void		print_hash_table(t_lsroom **hash_table)
{
	int			index;
	int			nb_coll;
	t_lsroom	*tmp;

	index = 0;
	nb_coll = 0;
	ft_printf("\n\t" BORD_LEFT "     HASH TABLE    " BORD_RIGHT "\n");
	while (index < HASH_SIZE)
	{
		if (hash_table[index] != NULL)
		{
			ft_printf(TMP_HASH, index);
			tmp = hash_table[index];
			if (tmp != NULL)
			{
				ft_printf(TMP_ROOM, TMP_NB, TMP_NAME, TMP_COORD, TMP_NEIGH);
				print_hash_rooms(tmp, &nb_coll);
			}
			write(1, "\n", 1);
		}
		index++;
	}
	ft_printf("\033[031;1mTotal number of collisions: %d\033[0m\n", nb_coll);
	ft_printf(BORD, BORD_LEFT, BORD_MIDD, BORD_RIGHT);
}

t_lsroom	*room_occur(t_lsroom *room_list, char *name)
{
	if (room_list == NULL)
		return (NEXIST);
	while (room_list != NULL)
	{
		if ((ft_strequ(room_list->room->name, name)))
			return (room_list);
		room_list = room_list->next;
	}
	return (NEXIST);
}

int			hash_value(char *str)
{
	unsigned long	hash;
	int				c;

	hash = 5381;
	while ((c = *str++))
		hash = ((hash << 5) + hash) + c;
	return (hash % HASH_SIZE);
}

int			create_hash_table(t_parser *prs)
{
	if (!(prs->hash_rooms = (t_lsroom**)malloc(sizeof(t_lsroom*) * HASH_SIZE)))
		return (ERROR);
	ft_bzero(prs->hash_rooms, sizeof(t_lsroom*) * HASH_SIZE);
	return (SUCCESS);
}
