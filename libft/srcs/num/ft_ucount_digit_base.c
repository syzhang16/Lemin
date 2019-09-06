/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ucount_digit_base.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarcena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 22:31:28 by acarcena          #+#    #+#             */
/*   Updated: 2018/10/23 22:32:24 by acarcena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_ucount_digit_base(unsigned long n, int base)
{
	int length;

	length = 1;
	while (n /= base)
		length++;
	return (length);
}
