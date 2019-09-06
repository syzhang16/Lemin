/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin_free.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarcena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 00:27:17 by acarcena          #+#    #+#             */
/*   Updated: 2018/03/12 00:27:20 by acarcena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnjoin_free(CHCST **s1, CHCST **s2, size_t len, size_t nb)
{
	char	*cat;
	size_t	len_s1;

	if (!s1 || !s2 || nb > 2)
		return (0);
	len_s1 = ft_strlen(*s1);
	if (len > ft_strlen(*s2))
		len = ft_strlen(*s2);
	if (!(cat = (char*)malloc(sizeof(char) * (len_s1 + len + 1))))
		return (NULL);
	ft_memmove(cat, *s1, len_s1);
	ft_memmove((cat + len_s1), *s2, len);
	cat[len_s1 + len] = '\0';
	ft_strdel((char**)s1);
	if (nb == 2)
		ft_strdel((char**)s2);
	return (cat);
}
