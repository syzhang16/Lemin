/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_bits.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarcena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 19:50:09 by acarcena          #+#    #+#             */
/*   Updated: 2018/03/25 20:09:32 by acarcena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_bits(unsigned char octet)
{
	int len;

	len = 7;
	while (len >= 0)
	{
		if (len == 3)
			write(1, " ", 1);
		if (((octet >> len) & 1) == 1)
			write(1, "1", 1);
		else
			write(1, "0", 1);
		len--;
	}
	write(1, "\n", 1);
}
