/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_lemin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syzhang <syzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 12:53:21 by acarcena          #+#    #+#             */
/*   Updated: 2019/06/25 00:29:27 by syzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		error_lemin(t_env *env)
{
	free_lemin(env, &env->parser, &env->solver);
	ft_printf("ERROR\n");
}
