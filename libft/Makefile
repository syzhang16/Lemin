# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acarcena <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/14 22:04:58 by acarcena          #+#    #+#              #
#    Updated: 2019/05/08 02:49:43 by acarcena         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -I./include

SRC_PATH = srcs
SRC_NAME = num/ft_atoi.c \
		   num/ft_atol.c \
		   num/ft_count_digit_base.c \
		   num/ft_itoa.c \
		   num/ft_itoa_base.c \
		   num/ft_ltoa_base.c \
		   num/ft_ltoa_base_buff.c \
		   num/ft_ucount_digit_base.c \
		   num/ft_ultoa_base.c \
		   num/ft_ultoa_base_buff.c \
		   maths/ft_factorial.c \
		   maths/ft_sqrt.c \
		   maths/ft_abs.c \
		   maths/ft_pow.c \
		   chr/ft_isalnum.c \
		   chr/ft_isalpha.c \
		   chr/ft_isascii.c \
		   chr/ft_isdigit.c \
		   chr/ft_isprint.c \
		   chr/ft_tolower.c \
		   chr/ft_toupper.c \
		   chr/ft_swap.c \
		   mem/ft_bzero.c \
		   mem/ft_memalloc.c \
		   mem/ft_memccpy.c \
		   mem/ft_memchr.c \
		   mem/ft_memcmp.c \
		   mem/ft_memcpy.c \
		   mem/ft_memdel.c \
		   mem/ft_memmove.c \
		   mem/ft_memset.c \
		   bitwise/ft_print_bits.c \
		   bitwise/ft_reverse_bits.c \
		   bitwise/ft_swap_bits.c \
		   output/ft_putchar_fd.c \
		   output/ft_putchar.c \
		   output/ft_putendl.c \
		   output/ft_putendl_fd.c \
		   output/ft_putnbr_fd.c \
		   output/ft_putnbr.c \
		   output/ft_putstr_fd.c \
		   output/ft_putstr.c \
		   str/ft_colchr.c \
		   str/ft_strcat.c \
		   str/ft_strchr.c \
		   str/ft_strclr.c \
		   str/ft_strcmp.c \
		   str/ft_strcpy.c \
		   str/ft_strdel.c \
		   str/ft_strdup.c \
		   str/ft_strequ.c \
		   str/ft_striter.c \
		   str/ft_striteri.c \
		   str/ft_strjoin.c \
		   str/ft_strjoin_free.c \
		   str/ft_strlcat.c \
		   str/ft_strlen.c \
		   str/ft_strmap.c \
		   str/ft_strmapi.c \
		   str/ft_strncat.c \
		   str/ft_strncmp.c \
		   str/ft_strncpy.c \
		   str/ft_strndup.c \
		   str/ft_strnequ.c \
		   str/ft_strnew.c \
		   str/ft_strnjoin_free.c \
		   str/ft_strnstr.c \
		   str/ft_strrchr.c \
		   str/ft_strrev.c \
		   str/ft_strsplit.c \
		   str/ft_strstr.c \
		   str/ft_strsub.c \
		   str/ft_strtoupper.c \
		   str/ft_strtrim.c \
		   str/get_next_line.c \
		   str/free_get_next_line.c \
		   lst/ft_lstadd.c \
		   lst/ft_lstdel.c \
		   lst/ft_lstdelone.c \
		   lst/ft_lstiter.c \
		   lst/ft_lstmap.c \
		   lst/ft_lstnew.c \
		   printf/buffer.c \
		   printf/ft_printf.c \
		   printf/get_directives.c \
		   printf/handle_char.c \
		   printf/handle_int.c \
		   printf/handle_misc_types.c \
		   printf/handle_string.c \
		   printf/handle_unsigned.c \
		   printf/handle_wchar.c \
		   printf/parse_format.c \
		   printf/type.c

OBJ_PATH = objs
OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
DIR	= $(sort $(dir $(OBJ)))

#==============================================================================#
#------------------------------------------------------------------------------#
all: $(NAME)

#==============================================================================#
#------------------------------------------------------------------------------#
$(NAME): $(DIR) $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "=~  → Libft - Compilation done ~="

#==============================================================================#
#------------------------------------------------------------------------------#
$(DIR):
	@mkdir -p $@

#==============================================================================#
#------------------------------------------------------------------------------#
$(OBJ_PATH)/%.o : $(SRC_PATH)/%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) -g $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

#==============================================================================#
#------------------------------------------------------------------------------#
clean:
	@rm -rf $(OBJ_PATH) 
	@echo "=~  → Libft - clean done ~="

#==============================================================================#
#------------------------------------------------------------------------------#
fclean: clean
	@rm -f $(NAME)
	@echo "=~  → Libft - fclean done ~="

#==============================================================================#
#------------------------------------------------------------------------------#
re:
	@make fclean
	@make all

#==============================================================================#
#------------------------------------------------------------------------------#
.PHONY: all clean fclean re
