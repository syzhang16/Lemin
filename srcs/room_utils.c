/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syzhang <syzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 06:33:23 by acarcena          #+#    #+#             */
/*   Updated: 2019/06/25 01:22:33 by syzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int	check_coord_validity(char *line)
{
	int 	index;
	int 	space;
	int 	sign;
	char	check;

	space = 0;
	sign = 0;
	index = 0;
	check = 0;
	while (line[index] != 0)
	{
		if (line[index] == '-' || line[index] == '+')
		{	
			check = 1;
			sign++;
		}
		else if (line[index] >= '0' && line[index] <= '9')
		{
			if (check == 1)
				check = 0;
			index++;
			continue ;
		}
		else if (line[index] == ' ')
		{
			if (check == 1)
				return (ERROR); 
			space++;
		}
		else
			return (ERROR);
		index++;
	}
	if (space != 1 || sign > 2 || index > 23)
		return (ERROR);
	return (SUCCESS);
}

static int	check_values(char *line, t_point *coord, char *space)
{
	long	tmp;
	int		pos_space;
	int		len_line;

	len_line = ft_strlen(line);
	pos_space = space - line;
	tmp = ft_atol(line);
	if (tmp < INT_MIN || tmp > INT_MAX)
		return (INV_X);
	else
		coord->x = tmp;
	tmp = ft_atol(line + pos_space);
	if (tmp < INT_MIN || tmp > INT_MAX)
		return (INV_Y);
	else
		coord->y = tmp;
	return (SUCCESS);
}

int			valid_coordinates(char *line, t_point *coord)
{
	char	*space;
	int		ret;

	if ((check_coord_validity(line)) != SUCCESS)
		return (ERROR);
	space = ft_strchr(line, ' ');
	if (space != NULL && space == ft_strrchr(line, ' '))
	{
		ret = check_values(line, coord, space);
		if (ret == INV_X || ret == INV_Y)
			return (ret);
	}
	else
		return (INV_SPACE);
	return (SUCCESS);
}

int			parse_command(t_status *status, char *line)
{
	if ((ft_strequ(line, STR_START)))
	{
		if (status->start == NOT_SET && status->end != TO_SET)
			status->start = TO_SET;
		else
			return (CONF_START);
	}
	else if ((ft_strequ(line, STR_END)))
	{
		if (status->end == NOT_SET && status->start != TO_SET)
			status->end = TO_SET;
		else
			return (CONF_END);
	}
	return (SUCCESS);
}

int			valid_name(char *line)
{
	int index;

	index = 0;
	if (line[index] == 76 || line[index] == ' ')
		return (0);
	while (line[index] != 0 && line[index] != ' ')
	{
		if (line[index] < 32 || line[index] > 126 || line[index] == 45)
			return (0);
		else
			index++;
	}
	if (line[index] == 0)
		return (0);
	else
		return (index);
}
