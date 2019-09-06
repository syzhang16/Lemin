/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarcena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 07:33:49 by acarcena          #+#    #+#             */
/*   Updated: 2017/12/04 15:02:53 by acarcena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	const char	*source;
	char		*dest;

	i = 0;
	source = (const char*)src;
	dest = (char*)dst;
	if (dest > source)
	{
		while (len-- >= 1)
			*(dest + len) = *(source + len);
	}
	else
	{
		while (i < len)
		{
			*(dest + i) = *(source + i);
			i++;
		}
	}
	return (dst);
}
