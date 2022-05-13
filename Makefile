# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/23 22:03:57 by nle-bret          #+#    #+#              #
#    Updated: 2022/05/12 16:05:32 by nle-bret         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS	= -Wall -Wextra -Werror

DEBUG	?= 0
ifeq ($(DEBUG), 1)
    CFLAGS += -g3 -fsanitize=address
endif

NAME	= push_swap.a

SRC		= push_swap.c\
		  sort_fct.c\
		  push_swap_utils.c\
		  make_list.c\
		  cost_fct.c\
		  big_sort_fct.c\
		  fct_lst_push_swap.c\
		  push_swap_fct.c\
		  push_swap_fct2.c
#		  ft_printf.c\
#		  ft_printf_utils.c\
#		  ft_printf_utils2.c\
#		  push_swap_fct.c

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
	$(CC) $(FLAGS) -I push_swap.h -c $<  -o $(<:.c=.o)

.PHONY: all clean fclean re
