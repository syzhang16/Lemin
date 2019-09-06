/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarcena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 13:26:44 by acarcena          #+#    #+#             */
/*   Updated: 2017/11/23 15:41:07 by acarcena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	l;
	char	*occ;
	size_t	len;

	i = 0;
	l = (char)c;
	occ = NULL;
	len = ft_strlen(s);
	while (i <= len)
	{
		if (s[i] == l)
			occ = (char*)(s + i);
		i++;
	}
	return (occ);
}
