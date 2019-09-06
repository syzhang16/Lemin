/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarcena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 01:19:24 by acarcena          #+#    #+#             */
/*   Updated: 2019/07/01 01:19:37 by acarcena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int	criterion(t_lsroom *cur, t_lsroom *nei, t_lsroom *start)
{
	if ((cur->room->child == nei->room
		|| (cur->room == start->room && nei->room->father == cur->room))
		|| (cur->room->father != nei->room
		&& cur->room->child != cur->room->parent
		&& cur->room->father != cur->room->parent
		&& (cur->room->child || cur->room->father)))
		return (0);
	return (1);
}

static int	bfs_loop(t_parser *prs, t_lsroom **queue, t_lsroom **tail)
{
	t_lsroom *qnei;
	t_lsroom *cur_queue;

	cur_queue = *queue;
	while (cur_queue)
	{
		qnei = cur_queue->room->nei;
		while (qnei)
		{
			if (criterion(cur_queue, qnei, prs->start)
				&& !qnei->room->visited)
			{
				qnei->room->parent = cur_queue->room;
				qnei->room->visited = 1;
				if (push_back_queue(qnei->room, tail) != SUCCESS)
					return (ERROR);
				if (qnei->room == prs->end->room)
					return (1);
			}
			qnei = qnei->next;
		}
		cur_queue = cur_queue->next;
	}
	return (0);
}

int			bfs(t_parser *parser)
{
	t_lsroom	*queue;
	t_lsroom	*tail;
	int			ret;

	queue = NULL;
	if ((list_room_nwadd(&queue, parser->start->room)))
		return (ERROR);
	tail = queue;
	reset_hash(parser);
	ret = bfs_loop(parser, &queue, &tail);
	free_lsroom_node(&queue);
	return (ret);
}
