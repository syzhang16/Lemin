/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarcena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 14:07:52 by acarcena          #+#    #+#             */
/*   Updated: 2018/03/23 00:35:00 by acarcena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	l;
	size_t	length;

	if (!s)
		return (NULL);
	i = 0;
	l = (char)c;
	length = ft_strlen(s);
	while (i < length)
	{
		if (s[i] == l)
			return ((char *)(s + i));
		i++;
	}
	return (NULL);
}
