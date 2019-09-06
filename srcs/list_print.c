/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syzhang <syzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 19:11:31 by acarcena          #+#    #+#             */
/*   Updated: 2019/06/25 00:40:26 by syzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		list_print(t_parser *parser, t_print **list, char **line)
{
	t_print *new;

	if (!(new = (t_print*)malloc(sizeof(t_print))))
		return (ERROR);
	new->line = *line;
	new->next = NULL;
	if (*list == NULL)
	{
		*list = new;
		parser->print_tail = new;
	}
	else
	{
		parser->print_tail->next = new;
		parser->print_tail = new;
	}
	*line = NULL;
	return (SUCCESS);
}
