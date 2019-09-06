/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarcena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 13:56:08 by acarcena          #+#    #+#             */
/*   Updated: 2017/12/04 14:58:15 by acarcena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	const char		*source;
	char			*dest;

	i = 0;
	source = (const char*)src;
	dest = (char *)dst;
	while (i < n)
	{
		*(dest + i) = *(source + i);
		if (*(source + i) == (const char)c)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
