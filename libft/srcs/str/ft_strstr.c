/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarcena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 16:00:26 by acarcena          #+#    #+#             */
/*   Updated: 2017/12/04 21:03:56 by acarcena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (needle[j] == '\0')
		return ((char*)haystack);
	while (haystack[i] != '\0' && needle[j] != '\0')
	{
		while (haystack[i] == needle[j])
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
