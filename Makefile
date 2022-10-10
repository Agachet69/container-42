# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agachet <agachet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/10 15:47:49 by agachet           #+#    #+#              #
#    Updated: 2022/10/10 15:52:41 by agachet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	ft_container

CC		=	clang++

FLAGS	=	-Werror -Wextra -Wall -std=c++98

SRCS	=	main.cpp

OBJS	=	$(SRCS:.cpp=.o)

%.o:	%.cpp
		@$(CC) $(FLAGS) -c $< -o $@

all:	$(NAME)

$(NAME):	$(OBJS)
			@$(CC) $(FLAGS) $(OBJS) -o $(NAME)
			@echo [$(NAME)]

clean:
		@rm -f $(OBJS)
		@echo [CLEAN]

fclean:
		@rm -f $(OBJS) $(NAME)
		@rm -f *_shrubbery
		@echo [FCLEAN]

re:		fclean all


.PHONY: re all fclean clean
