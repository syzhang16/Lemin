/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarcena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 15:50:47 by acarcena          #+#    #+#             */
/*   Updated: 2018/03/10 15:50:50 by acarcena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char *s2;

	if (!(s2 = (char*)malloc(sizeof(char) * (n + 1))))
		return (NULL);
	s2[n] = '\0';
	ft_strncpy(s2, s1, n);
	return (s2);
}
