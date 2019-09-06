/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarcena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 04:18:44 by acarcena          #+#    #+#             */
/*   Updated: 2019/04/30 22:38:13 by acarcena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int	start_to_end(t_env *env, t_parser *parser, t_solver *solver)
{
	t_paths *paths;
	t_clust *clust;

	paths = NULL;
	clust = NULL;
	if (env->args.no_graph == 0)
		print_graph(parser, 1);
	if (env->args.no_travel == 0)
		travel_start_end(parser, parser->end->room);
	if (create_paths(&paths) != SUCCESS)
		return (ERROR);
	if (list_room_nwadd(&paths->rooms, parser->end->room) != SUCCESS)
		return (ERROR);
	if (list_room_nwadd(&paths->rooms, parser->start->room) != SUCCESS)
		return (ERROR);
	paths->len = 1;
	solver->paths = paths;
	if (assign_clust(solver, &clust) != SUCCESS)
		return (ERROR);
	solver->nb_turns = 1;
	solver->clust = clust;
	return (SUCCESS);
}

static void	handle_args(t_env *env, t_parser *parser, t_solver *solver)
{
	if (env->args.print_hash == 1)
		print_hash_table(parser->hash_rooms);
	if (env->args.show_paths == 1)
		print_paths(solver->clust->paths);
}

static int	core_lemin(t_env *env, t_parser *prs, t_solver *solver)
{
	if (parse_graph(env, prs) != SUCCESS)
		return (ERROR);
	solver->nb_ants = prs->nb_ants;
	if (room_occur(prs->start->room->nei, prs->end->room->name) != NULL)
	{
		if (start_to_end(env, prs, solver) != SUCCESS)
			return (ERROR);
	}
	else
	{
		if (algorithm(prs, solver) != SUCCESS)
			return (ERROR);
		if (solver->clust == NULL)
			return (ERROR);
		if (solver->clust->paths != NULL)
			bubble(solver->clust->paths);
		if (env->args.no_graph == 0)
			print_graph(prs, 1);
		stop_ants(solver->clust);
		if (env->args.no_travel == 0)
			travel_ants(solver->clust);
	}
	return (SUCCESS);
}

int			main(int ac, char **av)
{
	t_env	env;

	(void)ac;
	ft_bzero(&env, sizeof(t_env));
	if ((get_args(&env.args, av)))
		return (ERROR);
	if (core_lemin(&env, &env.parser, &env.solver) != SUCCESS
		|| env.nb_error != 0)
	{
		error_lemin(&env);
		return (-1);
	}
	handle_args(&env, &env.parser, &env.solver);
	free_lemin(&env, &env.parser, &env.solver);
	return (0);
}
