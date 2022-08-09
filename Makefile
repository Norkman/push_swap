# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/23 22:03:57 by nle-bret          #+#    #+#              #
#    Updated: 2022/08/01 15:06:01 by nle-bret         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS	= -Wall -Wextra -Werror -g3 -fsanitize=address

DEBUG	?= 0
ifeq ($(DEBUG), 1)
    CFLAGS += -g3 -fsanitize=address
endif

NAME	= push_swap

SRC		= push_swap.c\
		  sort_fct.c\
		  push_swap_utils.c\
		  make_list.c\
		  cost_fct.c\
		  big_sort_fct.c\
		  fct_lst_push_swap.c\
		  push_swap_fct.c\
		  push_swap_fct2.c\
		  main.c\
		  cost_fct2.c\
		  cost_fct3.c\
		  cost_fct4.c

OBJS	= ${SRC:.c=.o}

CC		= gcc

HEADER	= push_swap.h

all: ${NAME}

${NAME}:  ${HEADER} ${OBJS}
	cd sources && $(MAKE)
	cp sources/libft.a .
	${CC} ${FLAGS} -o ${NAME} ${OBJS} libft.a

%.o: %.c
	$(CC) -c $(FLAGS) -Isources/ $< -o $@

clean:
	rm -f ${OBJS}
	$(MAKE) clean -C ./sources

fclean:	clean
	rm -f ${NAME}
	rm -f libft.a
	$(MAKE) fclean -C ./sources 

re:	fclean all

.PHONY: all clean fclean re
