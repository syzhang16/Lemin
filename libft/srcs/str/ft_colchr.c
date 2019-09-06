/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarcena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 04:11:26 by acarcena          #+#    #+#             */
/*   Updated: 2019/04/19 04:11:44 by acarcena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_colchr(char **map, int height, char val, int column)
{
	int	index;
	int	ret;

	index = 0;
	ret = 0;
	while (index < height)
	{
		if (map[index][column] == val)
			ret++;
		index++;
	}
	return (ret);
}
