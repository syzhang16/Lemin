/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarcena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 04:51:43 by acarcena          #+#    #+#             */
/*   Updated: 2018/03/09 21:30:43 by acarcena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;

	size += 1;
	if (!(str = (char*)malloc(sizeof(char) * size)))
		return (NULL);
	ft_bzero(str, size);
	return (str);
}
