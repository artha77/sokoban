##
## Makefile for my_printf in /home/artha/printf
## 
## Made by dylan renard
## Login   <artha@epitech.net>
## 
## Started on  Mon Nov  7 15:05:57 2016 dylan renard
## Last update Sun Dec 18 16:55:10 2016 dylan renard
##

CC	= 	gcc

RM	= 	rm -f

NAME	= 	my_sokoban

SRCS	=	src/input.c	\
		src/input2.c	\
		src/input3.c	\
		src/game.c	\
		src/map.c	\
		src/curse.c	\
		src/main.c

OBJS	= 	$(SRCS:.c=.o)

CFLAGS	+=	#-W -Wall -Werror -pedantic

CFLAGS	+=	-I./include/

LDFLAGS +=	-L./lib -lmy

all: libmy $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) -o $(NAME) $(CFLAFS) $(LDFLAGS) -lncurses

libmy:
	@$(MAKE) -C lib/my

clean:
	@$(RM) $(OBJS)
	@$(MAKE) clean -C lib/my

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: clean, re, all, fclean
