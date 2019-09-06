/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarcena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 02:53:54 by acarcena          #+#    #+#             */
/*   Updated: 2018/02/22 00:36:12 by acarcena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*cat;
	size_t	len_s1;
	size_t	len_s2;

	if (!s1 || !s2)
		return (0);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	if (!(cat = (char*)malloc(sizeof(char) * (len_s1 + len_s2 + 1))))
		return (NULL);
	ft_memmove(cat, s1, len_s1);
	ft_memmove((cat + len_s1), s2, len_s2);
	cat[len_s1 + len_s2] = '\0';
	return (cat);
}
