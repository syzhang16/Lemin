/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarcena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 11:02:23 by acarcena          #+#    #+#             */
/*   Updated: 2017/12/04 20:03:20 by acarcena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	char	*map;

	if (!s || !f)
		return (0);
	i = 0;
	if (!(map = (char *)malloc(sizeof(char) * (ft_strlen((char*)s) + 1))))
		return (NULL);
	while (s[i] != '\0')
	{
		map[i] = f(s[i]);
		i++;
	}
	map[i] = '\0';
	return (map);
}
