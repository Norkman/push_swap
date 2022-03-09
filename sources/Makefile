# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/23 22:03:57 by nle-bret          #+#    #+#              #
#    Updated: 2022/01/07 15:33:42 by nle-bret         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS	= -Wall -Wextra -Werror

DEBUG	?= 0
ifeq ($(DEBUG), 1)
    CFLAGS += -g3 -fsanitize=address
endif

NAME	= libft.a

SRC_DIR	= ./

SRC		= ft_bzero.c\
          ft_isalpha.c\
          ft_isdigit.c\
          ft_memcpy.c\
          ft_memset.c\
          ft_tolower.c\
          ft_toupper.c\
          ft_isalnum.c\
          ft_isascii.c\
          ft_isprint.c\
          ft_memmove.c\
          ft_strlen.c\
          ft_strlcpy.c\
          ft_strlcat.c\
          ft_strchr.c\
          ft_strrchr.c\
          ft_strncmp.c\
          ft_memchr.c\
          ft_memcmp.c\
          ft_strnstr.c\
          ft_atoi.c\
          ft_calloc.c\
          ft_strdup.c\
          ft_substr.c\
          ft_strjoin.c\
          ft_strtrim.c\
          ft_putchar_fd.c\
          ft_putstr_fd.c\
          ft_putendl_fd.c\
          ft_putnbr_fd.c\
          ft_split.c\
          ft_itoa.c\
          ft_strmapi.c\
          ft_striteri.c\
		  ft_convert_base.c\
		  ft_convert_base2.c\
		  ft_llutoa.c\
		  ft_putnbr_base.c\
		  ft_utoa.c

SRCS	= ${addprefix ${SRC_DIR}, ${SRC}}

BONUS	= ft_lstnew.c\
          ft_lstadd_front.c\
          ft_lstsize.c\
		  ft_lstlast.c\
		  ft_lstadd_back.c\
		  ft_lstdelone.c\
		  ft_lstclear.c\
		  ft_lstiter.c\
		  ft_lstmap.c

OBJS	= ${SRCS:.c=.o}

B_OBJS	= ${BONUS:.c=.o}

CC		= gcc

#so:
#	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRCS) $(BONUS)
#	gcc -nostartfiles -shared -o libft.so $(OBJS) $(B_OBJS)

${NAME}: ${OBJS}
	ar rc ${NAME} ${OBJS}

all: ${NAME}

bonus:    ${OBJS} ${B_OBJS}
	ar rc ${NAME} ${OBJS} ${B_OBJS}

clean:
	rm -f ${OBJS} ${B_OBJS}

fclean:	clean
	rm -f ${NAME}

re:	fclean all

.PHONY: all clean fclean re
