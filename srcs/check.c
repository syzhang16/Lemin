/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarcena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 02:11:51 by acarcena          #+#    #+#             */
/*   Updated: 2019/07/02 02:11:52 by acarcena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int			check_paths_validity(t_parser *parser, t_paths *paths)
{
	t_paths			*tmp;
	t_lsroom		*rom;

	tmp = paths;
	while (tmp)
	{
		rom = tmp->rooms;
		if (ft_strcmp(rom->room->name, parser->start->room->name) != 0)
			return (ERROR);
		while (rom->next)
		{
			if (room_occur(rom->room->nei, rom->next->room->name) == NEXIST)
				return (ERROR);
			rom = rom->next;
		}
		if (ft_strcmp(rom->room->name, parser->end->room->name) != 0)
			return (ERROR);
		tmp = tmp->next;
	}
	return (SUCCESS);
}

static int	second_row(t_parser *parser, t_paths *paths, t_lsroom *ltmp)
{
	t_lsroom	*adr;
	t_lsroom	*ltmp2;
	t_paths		*ptmp2;

	adr = ltmp;
	ptmp2 = paths;
	while (ptmp2)
	{
		ltmp2 = ptmp2->rooms;
		while (ltmp2 != NULL)
		{
			if (adr->room == ltmp2->room && !(adr->room == parser->start->room
				|| adr->room == parser->end->room) && adr != ltmp2)
				return (1);
			ltmp2 = ltmp2->next;
		}
		ptmp2 = ptmp2->next;
	}
	return (0);
}

int			check_overlaping(t_parser *parser, t_paths *paths)
{
	t_lsroom	*ltmp;
	t_paths		*ptmp;

	ptmp = paths;
	while (ptmp)
	{
		ltmp = ptmp->rooms;
		while (ltmp)
		{
			if (second_row(parser, paths, ltmp) == 1)
				return (1);
			ltmp = ltmp->next;
		}
		ptmp = ptmp->next;
	}
	return (0);
}
