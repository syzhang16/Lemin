/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa_base_buff.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarcena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 03:25:28 by acarcena          #+#    #+#             */
/*   Updated: 2018/10/22 03:25:37 by acarcena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_ltoa_base_buff(long n, int base, char *value)
{
	char	*tabval;
	int		len;

	len = ft_count_digit_base(n, base);
	tabval = "0123456789abcdef";
	value[len--] = '\0';
	if (n == 0)
		value[0] = '0';
	if (n < 0)
	{
		if (base == 10)
			value[0] = '-';
		value[len--] = tabval[(n % base) * -1];
		n /= base * -1;
	}
	while (n != 0)
	{
		value[len--] = tabval[n % base];
		n /= base;
	}
}
