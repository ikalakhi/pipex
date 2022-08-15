# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ikalakhi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/03 18:55:35 by ikalakhi          #+#    #+#              #
#    Updated: 2022/07/04 12:03:29 by ikalakhi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRC = pipex.c pipex_utils.c strjoin.c split.c strncmp.c substr.c

OBJS = $(SRC:.c=.o)
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)
$(NAME): $(OBJS)
	cc $(CFLAGS) $(SRC) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
