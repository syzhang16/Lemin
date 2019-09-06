# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: syzhang <syzhang@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/04 13:33:33 by syzhang           #+#    #+#              #
#    Updated: 2019/05/27 01:25:59 by acarcena         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


#  TO DO LIST   #
# Recreer la regle make ? / #

NAME = lem-in

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g

DEBUG = -g -fsanitize=address

CPPFLAGS = -I./include -I./libft/include

LDFLAGS = -L./libft
LDLIBS = -lft
LIB = ./libft/libft.a

#==============================================================================#
#------------------------------------LEM-IN------------------------------------#

INC_PATH_LEMIN = 	./include
INC_NAME_LEMIN = 	lemin.h

SRC_PATH_LEMIN = 	./srcs
SRC_NAME_LEMIN =	lemin.c \
					args.c \
					error_lemin.c \
					parse_utils.c \
					parsing.c \
					parse_rooms.c \
					free_lemin.c \
					free_hash.c \
					room_utils.c \
					hash_table.c \
					parse_tubes.c \
					print.c \
					list_room.c \
					list_tubes.c \
					list_paths.c \
					list_print.c \
					repartition.c \
					ants.c \
					algorithm.c \
					list_clust.c \
					bfs.c \
					paths.c \
					check.c

OBJ_PATH_LEMIN = ./objs
OBJ_NAME_LEMIN = $(SRC_NAME_LEMIN:.c=.o)

INC_LEMIN = $(addprefix $(INC_PATH_LEMIN)/,$(INC_NAME_LEMIN))
SRC_LEMIN = $(addprefix $(SRC_PATH_LEMIN)/,$(SRC_NAME_LEMIN))
OBJ_LEMIN = $(addprefix $(OBJ_PATH_LEMIN)/,$(OBJ_NAME_LEMIN))

#------------------------------------------------------------------------------#
#=================================PROGRESS BAR=================================#
#------------------------------------------------------------------------------#

# PROGRESS BAR
T = $(words $(SRC_NAME_LEMIN))
N = 0
C = $(words $N)$(eval N := x $N)
ECHO = "[`expr $C '*' 100 / $T`%]"

#Color
_GREY=\x1b[30m
_RED=\x1b[31m
_GREEN=\x1b[32m
_YELLOW=\x1b[33m
_BLUE=\x1b[34m
_PURPLE=\x1b[35m
_CYAN=\x1b[36m
_WHITE=\x1b[37m
_END=\x1b[0m

#------------------------------------------------------------------------------#
#=====================================RULES====================================#
#------------------------------------------------------------------------------#

all: $(NAME)
	
#==============================================================================#
#------------------------------------------------------------------------------#

$(NAME): $(OBJ_LEMIN)
	@make --silent -C libft
	@$(CC) $(CFLAGS) $(DEBUG) -o $(NAME) $(OBJ_LEMIN) $(LDFLAGS) $(LDLIBS)
	@echo  "\n=~  → lem-in - Compilation Done ~="

#==============================================================================#
#------------------------------------------------------------------------------#

$(OBJ_PATH_LEMIN)/%.o: $(SRC_PATH_LEMIN)/%.c $(INC_LEMIN)
	@mkdir -p $(OBJ_PATH_LEMIN)
	@printf "%-60b\r" "$(ECHO) $(_CYAN) Compiling lem-in: $< $(_END)"
	@$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

#==============================================================================#
#-------------------------------------CLEAN------------------------------------#

clean:
	@make --silent clean -C libft
	@rm -rf $(OBJ_PATH_LEMIN) 2> /dev/null || true
	@echo "=~  → lem-in - clean done ~="

#==============================================================================#
#------------------------------------FCLEAN------------------------------------#

fclean: clean
	@rm $(LIB) 2> /dev/null || true
	@echo "=~  → Libft - fclean done ~="
	@rm $(NAME) 2> /dev/null || true
	@echo "=~  → lem-in - fclean done ~="

#==============================================================================#
#--------------------------------------RE--------------------------------------#

re:
	@make fclean
	@make all

#==============================================================================#
#-----------------------------------.PHONY-------------------------------------#

.PHONY: clean fclean re all libs

