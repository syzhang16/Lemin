/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syzhang <syzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 19:54:43 by acarcena          #+#    #+#             */
/*   Updated: 2019/06/25 01:14:46 by syzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int	parse_ants(t_env *env, t_parser *parser, char **line)
{
	long	ants;

	ants = -1;
	while (ants == -1 && get_next_line(0, line, 0) > 0)
	{
		if (is_command(*line) == SUCCESS)
			return (ANT_CMD);
		else if (is_comment(*line) == SUCCESS)
		{
			if (list_print(parser, &parser->ls_print, line) != SUCCESS)
				return (ERROR);
			continue ;
		}
		else if (str_is_digit(*line, ANTS) == SUCCESS)
			ants = ft_atol(*line);
		else
			return (ERROR);
		if (list_print(parser, &parser->ls_print, line) != SUCCESS)
			return (ERROR);
	}
	if (ants <= 0 || ants > INT_MAX)
		return (ANT_NB);
	env->parser.nb_ants = ants;
	return (SUCCESS);
}

int			parse_graph(t_env *env, t_parser *parser)
{
	if ((env->nb_error = parse_ants(env, parser, &env->line)) != SUCCESS)
		return (ERROR);
	if ((env->nb_error = create_hash_table(parser)))
		return (ERROR);
	if ((env->nb_error = parse_rooms(&env->line, parser)))
		return (ERROR);
	if (parser->status.start != IS_SET || parser->status.end != IS_SET)
		return (ERROR);
	if (get_tube(env->line, parser) != SUCCESS)
		return (ERROR);
	if (list_print(parser, &parser->ls_print, &env->line) != SUCCESS)
		return (ERROR);
	if ((env->nb_error = parse_tubes(&env->line, &env->parser))
		&& env->nb_error != CONTINUE)
		return (ERROR);
	env->nb_error = 0;
	if (parser->end->room->nei == NULL || parser->end->room->nei == NULL)
		return (ERROR);
	return (SUCCESS);
}
