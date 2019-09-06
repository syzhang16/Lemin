/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_lemin.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarcena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 01:17:37 by acarcena          #+#    #+#             */
/*   Updated: 2019/05/24 01:17:39 by acarcena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_LEMIN_H
# define ERROR_LEMIN_H

# define MLC			"Invalid memory allocation "

# define STR_GNL 		"Error on GNL.\n"
# define STR_ANT_CMD	"Invalid command before the ants acquisition.\n"
# define STR_ANT_NB		"Invalid number of ants.\n"
# define STR_CONF_START	"Conflict while getting the starting room.\n"
# define STR_CONF_END	"Conflict while getting the ending room.\n"

# define STR_INV_NAME	"Invalid name.\n"
# define STR_ERR_NAME	"Invalid memory allocation for name.\n"

# define STR_INV_SPACE	"Invalid number of spaces in a room line.\n"
# define STR_INV_X		"Invalid coordinates: error on x.\n"
# define STR_INV_Y		"Invalid coordinates: error on y.\n"

# define STR_TUBES		"Should be tubes hehe.\n"

# define STR_INV_LINE	"Invalid line.\n"

# define STR_LST_ND		MLC" in list_room_add on the node.\n"
# define STR_LST_ST		MLC" in list_room_add on the room structure.\n"

# define FUCK_ERR		"OVERLAPPED\n"

/*
** n
** n
*/

# define GNL			2
# define ANT_CMD		3
# define ANT_NB			4
# define CONF_START		5
# define CONF_END		6

# define INV_SPACE		7
# define INV_X			8
# define INV_Y			9

# define INV_NAME		10
# define ERR_NAME		11

# define TUBES			99

# define INV_LINE		12

# define LST_ND			13
# define LST_ST			14

# define CONTINUE		15

# define FUCK 			35

#endif
