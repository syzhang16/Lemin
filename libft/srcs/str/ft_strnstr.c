/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarcena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 16:39:21 by acarcena          #+#    #+#             */
/*   Updated: 2017/12/04 12:49:20 by acarcena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (needle[j] == '\0')
		return ((char*)haystack);
	while (i < len && haystack[i] != '\0')
	{
		while (haystack[i] == needle[j] && i < len)
		{
			i++;
			j++;
			if (j == ft_strlen(needle))
				return ((char*)(haystack + i - j));
		}
		i = i - j + 1;
		j = 0;
	}
	return (NULL);
}
