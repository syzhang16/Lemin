/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_clust.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarcena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 19:01:13 by acarcena          #+#    #+#             */
/*   Updated: 2019/06/24 19:01:22 by acarcena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		assign_clust(t_solver *solver, t_clust **clust)
{
	t_clust *new;

	new = NULL;
	if (!((new) = (t_clust*)malloc(sizeof(t_clust))))
		return (ERROR);
	ft_bzero(new, sizeof(t_clust));
	*clust = new;
	(*clust)->nb_ants = solver->nb_ants;
	(*clust)->nb_paths = solver->nb_paths;
	(*clust)->paths = solver->paths;
	return (SUCCESS);
}
