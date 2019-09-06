/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_factorial.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarcena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 23:35:24 by acarcena          #+#    #+#             */
/*   Updated: 2017/12/05 23:40:15 by acarcena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_factorial(int nb)
{
	int	result;

	result = 1;
	if (nb < 0)
		result = 0;
	if (nb == 0 || nb == 1)
		result = 1;
	while (nb > 1)
	{
		result *= nb;
		nb--;
	}
	return (result);
}
