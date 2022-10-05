# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agachet <agachet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/14 18:52:17 by agachet           #+#    #+#              #
#    Updated: 2021/10/26 17:29:34 by agachet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= megaphone

CC		= clang++

SRCS 	= test.cpp

OBJS	= $(SRCS:.cpp=.o)

FLAGS	= -Wall -Wextra -Werror

%.o:	%.cpp
		$(CC) $(FLAGS) -c $< -o $@

all:		$(NAME)

$(NAME)	:	$(OBJS)
			$(CC) $(FLAGS) $(OBJS) -o $(NAME)

clean:
		rm -f $(OBJS)

fclean:
		rm -rf ${NAME} $(OBJS)

re:		fclean all

.PHONY: all fclean re