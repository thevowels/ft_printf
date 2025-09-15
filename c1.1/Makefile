# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/14 23:02:14 by aphyo-ht          #+#    #+#              #
#    Updated: 2025/09/16 05:21:41 by aphyo-ht         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a
INCLUDE		= include
LIBFT		= libft
SRC_DIR		= src/
OBJ_DIR		= obj/
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
ARFLAGS		= rcs

SRC_FILES	= ft_printf.c 

SRC			= $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ			= $(addprefix $(OBJ_DIR), $(SRC_FILES:.c=.o))



$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
			$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $@

all:		$(NAME) 

$(OBJ_DIR):
			mkdir -p $(OBJ_DIR)

$(NAME):	$(OBJ)
			make -C $(LIBFT)
			cp libft//libft.a .
			mv libft.a $(NAME)
			$(AR) $(ARFLAGS) $(NAME) $(OBJ)

clean:
			$(RM) -rf $(OBJ_DIR)
			@make clean -C $(LIBFT)

fclean:		clean
			$(RM) -f $(NAME)
			$(RM) -f $(LIBFT)/libft.a

re:			fclean all

.PHONY:		all clean fclean re