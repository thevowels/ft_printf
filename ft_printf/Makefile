# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/16 06:00:39 by aphyo-ht          #+#    #+#              #
#    Updated: 2025/09/16 09:08:22 by aphyo-ht         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a


CC			= cc
CFLAGS		= -Wall -Wextra -Werror
AR			= ar
ARFLAGS		= rcs
SRC			= ft_printf.c 

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(ARFLAGS) -o $(NAME) $(OBJ)

clean:
		rm -f $(OBJ)
		
fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re