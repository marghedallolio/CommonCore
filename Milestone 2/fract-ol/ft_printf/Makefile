# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdalloli <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/29 12:04:04 by mdalloli          #+#    #+#              #
#    Updated: 2024/11/29 12:04:05 by mdalloli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#nome della libreria
NAME = ft_printf.a

#compilatore
CC = cc

#flags di compilazione
CFLAGS = -Wall -Werror -Wextra

#lists dei file sorgente
SRC = \
	ft_printf.c ft_putchar.c ft_puthex.c ft_putnbr.c ft_putptr.c ft_putstr.c \
	ft_putunsigned.c

#genera il nome dei file oggetto (.o) a partire dai file sorgente (.c)
OBJ = $(SRC:.c=.o)

#regola principale per creare la libreria
all: $(NAME)

#creazione della libreria statica
$(NAME): $(OBJ)
	ar rc $@ $?

#compilazione dei file sorgente
%.o: %.c
	$(CC) $(CFLAGS) -c $?

#pulizia dei file oggetto
clean:
	rm -f $(OBJ)

#rimozione di file oggetto e libreria
fclean: clean
	rm -f $(NAME)

#ricompilazione completa
re: fclean all

.PHONY: all clean fclean re
