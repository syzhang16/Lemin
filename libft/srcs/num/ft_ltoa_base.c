/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarcena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 22:19:53 by acarcena          #+#    #+#             */
/*   Updated: 2018/10/23 22:21:05 by acarcena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ltoa_base(long n, int base)
{
	char	*value;
	char	*tabval;
	int		len;

	len = ft_count_digit_base(n, base);
	if (!(value = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
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
	return (value);
}
