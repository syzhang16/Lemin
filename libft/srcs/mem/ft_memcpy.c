/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarcena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 07:49:44 by acarcena          #+#    #+#             */
/*   Updated: 2017/12/04 14:48:31 by acarcena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	const char	*source;
	char		*dest;

	i = 0;
	source = (const char*)src;
	dest = (char*)dst;
	while (i < n)
	{
		*(dest + i) = *(source + i);
		i++;
	}
	return (dest);
}
