/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarcena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 10:06:23 by acarcena          #+#    #+#             */
/*   Updated: 2017/12/04 16:16:58 by acarcena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*mem;
	size_t	i;

	if (!(mem = malloc(size)))
		return (NULL);
	i = 0;
	while (i < size)
	{
		mem[i] = 0;
		i++;
	}
	return ((void*)mem);
}
