/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarcena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 18:59:28 by acarcena          #+#    #+#             */
/*   Updated: 2019/06/29 13:51:40 by acarcena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

/*
**	LIBS
*/

# include "libft.h"
# include "error_lemin.h"

/*
**	DEFINE
*/

# define ARG_V			"-v"
# define ARG_PH			"-ph"
# define ARG_SP			"-sp"
# define ARG_NG			"-ng"
# define ARG_NT			"-nt"

# define NOT_SET		0
# define TO_SET			1
# define IS_SET			2

# define INVALID		-1

# define HASH_POW		157
# define HASH_SIZE		32768

# define STR_START		"##start"
# define STR_END		"##end"

# define NEXIST			NULL

# define GRADE			1
# define CLEAN			2
# define RESET			3

# define ANTS			1
# define COORD			2

# define PRINT			1

/*
**	DEFINE -> HASH_TABLE:
*/

# define TMP_NB			"  INDEX"
# define TMP_NAME		"         NAME"
# define TMP_COORD		"    COORDINATES - (x/y)"
# define TMP_NEIGH		"                    NEIGHBOURS"
# define TMP_ROOM		"\n\033[32;4m%-10s | %-25s | %-30s | %-50s\033[0m\n"

# define BORDER			"\033[31;1m#---------------------------------#\033[0m"
# define BORD			"%s%s%s\n"
# define BORD_LEFT		"\033[31;1m#-----------------------------------------"
# define BORD_MIDD		"--------------------------------------"
# define BORD_RIGHT		"--------------------------------------------#\033[0m"
# define TMP_HASH		"\n\033[36;1;4mHASH\033[0m\t\t\t\033[0;36m%d\033[0m\n"

/*
*******************************************************************************
*******************************************************************************
*/

/*
**	STRUCTURES
*/

typedef struct		s_stroom
{
	char			*name;
	t_point			coord;
	int				visited;

	struct s_lsroom	*nei;

	struct s_stroom	*parent;
	struct s_stroom	*child;
	struct s_stroom	*father;

	unsigned int	ant;
}					t_stroom;

typedef struct		s_lsroom
{
	t_stroom		*room;
	struct s_lsroom	*next;
}					t_lsroom;

/*
*******************************************************************************
*******************************************************************************
*/

typedef struct		s_paths
{
	unsigned int	len;
	unsigned int	ants_limit;
	t_lsroom		*rooms;
	struct s_paths	*next;
}					t_paths;

typedef struct		s_clust
{
	unsigned int	nb_ants;
	unsigned int	nb_paths;
	unsigned int	nb_turns;
	t_paths			*paths;
	unsigned int	ants_gone;
	unsigned int	biggest;
	unsigned int	rest;
}					t_clust;

typedef struct		s_solver
{
	unsigned int	nb_ants;

	unsigned int	max_paths;
	unsigned int	nb_paths;
	t_paths			*paths;
	t_paths			*tail_paths;

	t_paths			*shortest;
	unsigned int	len_shortest;
	unsigned int	biggest;

	t_lsroom		*queue;
	t_lsroom		*tail_ls;

	unsigned int	nb_turns;
	t_clust			*clust;
}					t_solver;

/*
*******************************************************************************
*******************************************************************************
*/

typedef struct		s_args
{
	unsigned char	verbose;
	unsigned char	print_hash;
	unsigned char	show_turns;
	unsigned char	show_paths;
	unsigned char	no_graph;
	unsigned char	no_travel;
}					t_args;

typedef struct		s_print
{
	char			*line;
	struct s_print	*next;
}					t_print;

typedef struct		s_status
{
	unsigned char	start;
	unsigned char	end;
}					t_status;

typedef struct		s_parser
{
	unsigned int	nb_ants;
	unsigned int	nb_rooms;
	t_print			*ls_print;
	t_print			*print_tail;
	t_status		status;
	t_lsroom		**hash_rooms;
	t_lsroom		*start;
	t_lsroom		*end;
}					t_parser;

typedef struct		s_env
{
	t_args			args;
	char			*line;
	t_parser		parser;
	t_solver		solver;
	unsigned int	nb_error;
}					t_env;

/*
*******************************************************************************
*******************************************************************************
*/

/*
**	FONCTIONS
*/

/*
**	algorithm.c
*/

void				reset_hash(t_parser *lparser);
int					algorithm(t_parser *parser, t_solver *solver);

/*
**	ants.c
*/

void				travel_start_end(t_parser *parser, t_stroom *end);
void				travel_ants(t_clust *clust);

/*
**	args.c
*/

int					get_args(t_args *args, char **av);

/*
**	bfs.c
*/

int					bfs(t_parser *parser);

/*
**	check.c
*/

int					check_paths_validity(t_parser *parser, t_paths *paths);
int					check_overlaping(t_parser *parser, t_paths *paths);

/*
**	error_lemin.c
*/

void				error_lemin(t_env *env);

/*
**	free_hash.c
*/

void				free_lsroom_node(t_lsroom **lsroom);
void				free_stroom(t_stroom *room);
void				free_lsroom_hash(t_lsroom **lsroom);
void				free_hashtable(t_lsroom **hash_rooms);

/*
**	free_lemin.c
*/

void				free_clust(t_clust **clust);
void				free_paths(t_paths **paths);
void				free_line(t_env *env);
void				free_lemin(t_env *env, t_parser *parser, t_solver *solver);

/*
**	hash_table.c
*/

void				print_hash_table(t_lsroom **hash_table);
t_lsroom			*room_occur(t_lsroom *room_list, char *name);
int					hash_value(char *str);
int					create_hash_table(t_parser *pars);

/*
**	lemin.c
*/

int					main(int ac, char **av);

/*
**	list_clust.c
*/

int					assign_clust(t_solver *solver, t_clust **clust);

/*
**	list_paths.c
*/

void				pop_paths(t_paths **paths);
int					push_paths(t_solver *solver, t_paths *paths);
int					create_paths(t_paths **paths);

/*
**	list_print.c
*/

int					list_print(t_parser *parser, t_print **list, char **line);

/*
**	list_room.c
*/

void				list_room_delnode(t_lsroom **list, t_stroom *room);
int					list_room_new(t_lsroom **room_node, t_stroom room_content);
void				list_room_add(t_lsroom **list, t_lsroom *new_room);
int					list_room_nwadd(t_lsroom **list, t_stroom *room);
int					lsroom_back(t_lsroom **ls, t_stroom *r, t_lsroom **tail);

/*
**	list_tubes.c
*/

void				pop_queue(t_lsroom **lsroom);
int					push_queue(t_lsroom **lsroom, t_stroom *room);
int					push_back_queue(t_stroom *room, t_lsroom **tail);
t_lsroom			*find_node(t_lsroom **list, t_stroom *room);

/*
**	parse_rooms.c
*/

int					parse_rooms(char **line, t_parser *parser);

/*
**	parse_tubes.c
*/

int					get_tube(char *line, t_parser *parser);
int					parse_tubes(char **line, t_parser *parser);

/*
**	parse_utils.c
*/

char				is_command(char *line);
char				is_comment(char *line);
char				str_is_digit(char *line, int format);
char				is_room(char *line);
char				is_tube(char *line);

/*
**	parsing.c
*/

int					parse_command(t_status *status, char *line);
int					parse_graph(t_env *env, t_parser *parser);

/*
**	paths.c
*/

int					get_paths(t_parser *prs, t_solver *solver);

/*
**	print.c
*/

void				print_list(t_lsroom *list);
void				print_graph(t_parser *parser, int format);
void				print_paths(t_paths *paths);

/*
**	repartition.c
*/

void				bubble(t_paths *all_paths);
void				stop_ants(t_clust *clust);
void				number_turns(t_clust *clust);

/*
**	room_utils.c
*/

int					valid_coordinates(char *line, t_point *coord);
int					valid_name(char *line);

#endif
