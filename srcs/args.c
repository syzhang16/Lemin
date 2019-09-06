/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syzhang <syzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 23:37:00 by acarcena          #+#    #+#             */
/*   Updated: 2019/06/25 00:27:58 by syzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	error_args(void)
{
	ft_printf("USAGE: ./lem-in [OPTIONS] < MAP\n AVAILABLE OPTIONS:\n");
	ft_printf("\t* -v  : Verbose. Print a valid error message describing ");
	ft_printf("what happened in the program;\n");
	ft_printf("\t* -ph : Print the hash_table containing all the rooms;\n");
	ft_printf("\t* -sp : Print the path(s) used by the ants colony;\n");
	ft_printf("\t* -ng : Doesn't print the original graph;\n");
	ft_printf("\t* -nt : Doesn't print the ants getting through the graph.\n");
}

int			get_args(t_args *args, char **av)
{
	av++;
	while (*av)
	{
		if (ft_strequ(ARG_V, *av))
			args->verbose = 1;
		else if (ft_strequ(ARG_PH, *av))
			args->print_hash = 1;
		else if (ft_strequ(ARG_SP, *av))
			args->show_paths = 1;
		else if (ft_strequ(ARG_NG, *av))
			args->no_graph = 1;
		else if (ft_strequ(ARG_NT, *av))
			args->no_travel = 1;
		else
		{
			error_args();
			return (1);
		}
		av++;
	}
	return (0);
}
