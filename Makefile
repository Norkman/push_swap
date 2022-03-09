# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/23 22:03:57 by nle-bret          #+#    #+#              #
#    Updated: 2022/03/04 12:09:15 by nle-bret         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS	= -Wall -Wextra -Werror

DEBUG	?= 0
ifeq ($(DEBUG), 1)
    CFLAGS += -g3 -fsanitize=address
endif

NAME	= libftpush_swap.a

SRC		= push_swap.c

OBJS	= ${SRC:.c=.o}

CC		= gcc

${NAME}: ${OBJS}
	cd sources && $(MAKE)
	cp sources/libft.a $(NAME)
	ar -rcs $(NAME) $(OBJS)

all: ${NAME}

clean:
	rm -f ${OBJS}
	$(MAKE) clean -C ./sources

fclean:	clean
	rm -f ${NAME}
	rm -f libft.a
	$(MAKE) fclean -C ./sources 

re:	fclean all

%.o: %.c
	$(CC) $(FLAGS) -I push_swap.h.h -c $<  -o $(<:.c=.o)

.PHONY: all clean fclean re
