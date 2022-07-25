# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anfreire <anfreire@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/03 08:30:11 by anfreire          #+#    #+#              #
#    Updated: 2022/07/07 01:22:19 by anfreire         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRCS = $(wildcard *.c)
            
CC = gcc

CFLAGS = -lpthread -fsanitize=thread

OBJS = $(SRCS:.c=.o)

FLAGS		= -Wall -Wextra -Werror

all			:	$(NAME)

$(NAME)		:	$(OBJS)
		@gcc $(CFLAGS) -o $(NAME) $(OBJS)
		@echo	""
		@echo	"$$ ./philo && Object Files Generated"
		@echo	""
%.o			:	%.c
		@gcc $(FLAGS) -c $^ -I./ -o $@

clean		:
		@rm -f $(OBJS)
		@echo	""
		@echo	"$$ Object Files Deleted"
		@echo	""

fclean		:	clean
		@rm -f $(NAME)
		@echo	""
		@echo	"$$ ./philo Deleted"
		@echo	""

re			:	fclean all

.PHONY		:	all clean fclean re bonus
