/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarcena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 02:09:44 by acarcena          #+#    #+#             */
/*   Updated: 2018/03/06 02:10:00 by acarcena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free(char const **s1, char const **s2, size_t nb)
{
	char	*cat;
	size_t	len_s1;
	size_t	len_s2;

	if (!s1 || !s2 || nb > 2)
		return (0);
	len_s1 = ft_strlen(*s1);
	len_s2 = ft_strlen(*s2);
	if (!(cat = (char*)malloc(sizeof(char) * (len_s1 + len_s2 + 1))))
		return (NULL);
	ft_memmove(cat, *s1, len_s1);
	ft_memmove((cat + len_s1), *s2, len_s2);
	cat[len_s1 + len_s2] = '\0';
	ft_strdel((char**)s1);
	return (cat);
}
