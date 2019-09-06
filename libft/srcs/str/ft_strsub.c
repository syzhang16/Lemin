/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarcena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 07:56:07 by acarcena          #+#    #+#             */
/*   Updated: 2017/12/04 20:57:12 by acarcena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char		*tron;
	size_t		i;

	if (!s)
		return (0);
	i = start;
	if (!(tron = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (s[i] != '\0' && (i - start) <= len)
	{
		tron[i - start] = s[i];
		i++;
	}
	tron[len] = '\0';
	return (tron);
}
