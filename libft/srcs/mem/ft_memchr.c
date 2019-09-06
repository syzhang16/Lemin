/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarcena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 08:12:30 by acarcena          #+#    #+#             */
/*   Updated: 2017/12/03 15:30:42 by acarcena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	l;

	i = 0;
	l = (unsigned char)c;
	str = (unsigned char*)s;
	while (i < n)
	{
		if (str[i] == l)
			return ((void*)(s + i));
		i++;
	}
	return (NULL);
}
