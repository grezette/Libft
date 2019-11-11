# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: grezette <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/10 10:19:29 by grezette          #+#    #+#              #
#    Updated: 2019/11/10 19:03:40 by grezette         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a

SRCS		=	ft_memset.c \
				ft_bzero.c \
				ft_memcpy.c \
				ft_memccpy.c \
				ft_memmove.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_strlen.c \
				ft_isalpha.c \
				ft_isdigit.c \
				ft_isalnum.c \
				ft_isprint.c \
				ft_isascii.c \
				ft_tolower.c \
				ft_toupper.c \
				ft_strdup.c \
				ft_strchr.c \
				ft_strrchr.c \
				ft_strncmp.c \
				ft_strlcat.c \
				ft_strlcpy.c \
				ft_strnstr.c \
				ft_atoi.c \
				ft_calloc.c \
				ft_substr.c \
				ft_strjoin.c \
				ft_strtrim.c \
				ft_split.c \
				ft_itoa.c \
				ft_strmapi.c \
				ft_putchar_fd.c \
				ft_putstr_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c \

SRCS_BONUS	=	ft_lstnew.c \
				ft_lstsize.c \
				ft_lstadd_back.c \
				ft_lstadd_front.c \
				ft_lstlast.c \
				ft_lstdelone.c \
				ft_lstclear.c \
				ft_lstiter.c \
				ft_lstmap.c \


OBJS		=	${SRCS:.c=.o}

OBJS_BONUS	=	${SRCS_BONUS:.c=.o}

LIB_PATH	=	-L. -lft

CC		=	gcc

FLAGS		=	-Wall -Wextra -Werror

${NAME}:		${OBJS}
			ar rc ${NAME} ${OBJS}

all:			${NAME}

bonus:			${OBJS} ${OBJS_BONUS}
			ar rc ${NAME} ${OBJS} ${OBJS_BONUS}

.c.o:			${SRCS} ${SRCS_BONUS}
			${CC} ${FLAGS} ${INC_PATH} -c $<  -o ${<:.c=.o}

clean:
			rm -f ${OBJS} ${OBJS_BONUS}

fclean:			clean
			rm -f ${NAME}

re:			fclean all
