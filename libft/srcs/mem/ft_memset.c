/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarcena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 09:22:04 by acarcena          #+#    #+#             */
/*   Updated: 2017/12/02 10:20:13 by acarcena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*str;
	unsigned char	l;
	size_t			i;

	i = 0;
	str = (unsigned char*)b;
	l = (unsigned char)c;
	while (i < len)
	{
		str[i] = l;
		i++;
	}
	return ((void*)str);
}
