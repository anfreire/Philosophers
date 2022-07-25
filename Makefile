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

CFLAGS = -Wall -Wextra -Werror -lpthread -fsanitize=0 -fsanitize=thread

OBJS = $(SRCS:.c=.o)

FLAGS		= -Wall -Wextra -Werror

all			:	$(NAME)

$(NAME)		:	$(OBJS)
		@gcc -o $(NAME) $(OBJS)
		@echo	"\n$$ ./philo && Object Files Generated\n"
%.o			:	%.c
		@gcc $(FLAGS) -c $^ -I./ -o $@

clean		:
		@rm -f $(OBJS)
		@echo	"\n$$ Object Files Deleted\n"

fclean		:	clean
		@rm -f $(NAME)
		@echo	"\n$$ ./philo Deleted\n"

re			:	fclean all

.PHONY		:	all clean fclean re bonus

NAME = philo

SRCS = $(wildcard *.c)
            
CC = gcc

OBJS = $(SRCS:.c=.o)

FLAGS		= -Wall -Wextra -Werror -fsanitize=thread

all			:	$(NAME)

$(NAME)		:	$(OBJS)
		@gcc -lpthread -fsanitize=thread -o $(NAME) $(OBJS)
		@echo	"$$ ./philo && Object Files Generated"
		@echo	""
%.o			:	%.c
		@gcc $(FLAGS) -c $^ -I./ -o $@

clean		:
		@rm -f $(OBJS)NAME = philo

SRCS = $(wildcard *.c)
            
CC = gcc

OBJS = $(SRCS:.c=.o)

FLAGS		= -Wall -Wextra -Werror -fsanitize=thread

all			:	$(NAME)

$(NAME)		:	$(OBJS)
		@gcc -lpthread -fsanitize=thread -o $(NAME) $(OBJS)
		@echo	"$$ ./philo && Object Files Generated"
		@echo	""
%.o			:	%.c
		@gcc $(FLAGS) -c $^ -I./ -o $@

clean		:
		@rm -f $(OBJS)
		@echo	"$$ Object Files Deleted"
		@echo	""

fclean		:	clean
		@rm -f $(NAME)
		@echo	"$$ ./philo Deleted"
		@echo	""

re			:	fclean all

.PHONY		:	all clean fclean re bonus
		@echo	"$$ Object Files Deleted"
		@echo	""

fclean		:	clean
		@rm -f $(NAME)
		@echo	"$$ ./philo Deleted"
		@echo	""

re			:	fclean all

.PHONY		:	all clean fclean re bonus
