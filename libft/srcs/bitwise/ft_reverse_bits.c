/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_bits.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarcena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 19:55:34 by acarcena          #+#    #+#             */
/*   Updated: 2018/03/28 22:29:20 by acarcena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned char	ft_reverse_bits(unsigned char octet)
{
	int				len;
	unsigned char	octet2;
	unsigned char	tmp;

	octet2 = 0;
	len = 8;
	while (len--)
	{
		tmp = octet << len;
		tmp >>= 7;
		octet2 = octet2 | tmp;
		len--;
		octet2 <<= 1;
	}
	return (octet);
}
