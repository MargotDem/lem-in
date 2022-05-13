# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mde-maul <mde-maul@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/13 10:45:52 by mde-maul          #+#    #+#              #
#    Updated: 2022/05/13 10:45:53 by mde-maul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

SRCS = main.c handle_error.c

OBJS = $(SRCS:.c=.o)

FLAGS = -Wall -Werror -Wextra

LIBS = -L ./libft -lft

INCLUDES = -I ./

all: $(NAME)

$(NAME):
	make -C ./libft
	gcc $(FLAGS) $(INCLUDES) -c $(SRCS)
	gcc $(FLAGS) $(INCLUDES) -o $(NAME) $(OBJS) $(LIBS)

clean:
	make -C ./libft clean
	rm -f $(OBJS)

fclean: clean
	make -C ./libft fclean
	rm -f $(NAME)

re: fclean all

dev:
	gcc $(FLAGS) $(INCLUDES) -c $(SRCS)
	gcc $(FLAGS) $(INCLUDES) -o $(NAME) $(OBJS) $(LIBS)
