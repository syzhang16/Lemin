/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarcena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 02:17:37 by acarcena          #+#    #+#             */
/*   Updated: 2019/06/11 02:17:40 by acarcena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		print_list(t_lsroom *list)
{
	while (list != NULL)
	{
		ft_printf("%s ", list->room->name);
		list = list->next;
	}
	ft_printf("\n");
}

void		print_paths(t_paths *paths)
{
	ft_printf("\n \033[033;1m## ----- PATHS ----- ##\033[0m\n\n");
	while (paths != NULL)
	{
		ft_printf("\033[032;1mLEN:\033[0m %4d", paths->len);
		ft_printf(" -- \033[032;1mROOMS:\033[0m ");
		print_list(paths->rooms);
		paths = paths->next;
	}
	ft_printf("\n");
}

void		print_graph(t_parser *parser, int format)
{
	t_print *tmp;

	while (parser->ls_print != NULL)
	{
		if (format == PRINT)
			ft_printf("%s\n", parser->ls_print->line);
		free(parser->ls_print->line);
		tmp = parser->ls_print;
		parser->ls_print = parser->ls_print->next;
		free(tmp);
	}
	if (format == PRINT)
		ft_printf("\n");
}
