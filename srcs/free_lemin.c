/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_filler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarcena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 04:18:44 by acarcena          #+#    #+#             */
/*   Updated: 2018/03/15 20:46:50 by acarcena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	free_paths(t_paths **paths)
{
	t_paths *tmp;

	while (*paths)
	{
		free_lsroom_node(&(*paths)->rooms);
		tmp = (*paths)->next;
		free(*paths);
		*paths = NULL;
		*paths = tmp;
	}
}

void	free_clust(t_clust **clust)
{
	free_paths(&(*clust)->paths);
	free(*clust);
}

void	free_line(t_env *env)
{
	free(env->line);
	env->line = NULL;
}

void	free_lemin(t_env *env, t_parser *parser, t_solver *solver)
{
	if (env->line != NULL)
		free_line(env);
	if (parser->hash_rooms != NULL)
		free_hashtable(parser->hash_rooms);
	if (parser->ls_print != NULL)
		print_graph(parser, 0);
	if (solver->clust != NULL)
		free_clust(&solver->clust);
	get_next_line(0, &env->line, 1);
}
