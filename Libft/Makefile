# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdalloli <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/22 12:13:07 by mdalloli          #+#    #+#              #
#    Updated: 2024/11/22 12:13:09 by mdalloli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#nome della libreria
NAME = libft.a

#compilatore
CC = gcc

#flags di compilazione
CFLAGS = -Wall -Wextra -Werror

#lista dei file sorgente
SRC = ft_*.c

#genera il nome dei file oggetto (.o) a partire ai file sorgente (.c)
OBJ = $(SRC:.c=.o)

#regola principale per creare la libreria
all: $(NAME)

#creazione della libreria statica
$(NAME): $(OBJ)
	ar rcs $@ %^

#compilazione dei file sorgente
%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@

#pulizia dei file oggetto
clean:
	rm -f $(OBJ)

#rimozione di file oggetto e libreria
fclean: clean
	rm -f $(OBJ)

#ricompilazione completa
re: fclean all
