/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_digit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarcena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 13:38:46 by acarcena          #+#    #+#             */
/*   Updated: 2018/11/04 19:32:16 by acarcena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_digit_base(long n, int base)
{
	int length;

	length = 1;
	if (n < 0)
	{
		if (base == 10)
			length++;
		n *= -1;
	}
	while (n /= base)
		length++;
	return (length);
}
