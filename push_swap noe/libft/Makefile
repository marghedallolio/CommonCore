# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: npezzati <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/25 18:06:56 by npezzati          #+#    #+#              #
#    Updated: 2024/11/29 10:07:02 by npezzati         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#nome della libreria
NAME = libft.a

#compilatore
CC = gcc

#flags di compilazione
CFLAGS = -Wall -Wextra -Werror

#lista dei file sorgente
SRC = \
	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c \
	ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c \
	ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c \
	ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
	ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_calloc.c ft_strdup.c \
	ft_printf.c  ft_putchar.c  ft_putnbr.c	ft_putstr.c ft_puthex.c   ft_putptr.c	\
	ft_putunsigned.c ft_lstsize.c 
	
OBJ = $(SRC:.c=.o)

#regola principale per creare la libreria
all: $(NAME)

#creazione della libreria statica
$(NAME): $(OBJ)
	ar rc $@ $?

%.o: %.c
	$(CC) $(CFLAGS) -c $?

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

#ricompilazione completa
re: fclean all

.PHONY: all clean fclean re
