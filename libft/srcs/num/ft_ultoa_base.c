/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarcena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 03:25:28 by acarcena          #+#    #+#             */
/*   Updated: 2018/10/22 03:25:37 by acarcena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ultoa_base(unsigned long n, int base)
{
	char	*value;
	char	*tabval;
	int		len;

	len = ft_ucount_digit_base(n, base);
	if (!(value = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	tabval = "0123456789abcdef";
	value[len--] = '\0';
	if (n == 0)
		value[0] = '0';
	while (n != 0)
	{
		value[len--] = tabval[n % base];
		n /= base;
	}
	return (value);
}
