# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdalloli <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/15 11:02:48 by mdalloli          #+#    #+#              #
#    Updated: 2025/01/15 11:02:50 by mdalloli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#nome della libreria
NAME = so_long

#compilatore
CC = cc

#flags di compilazione
CFLAGS = -Wall -Wextra -Werror

#lista dei file sorgente
SRC = \
	

BONUS_SRC = \
	

#genera il nome dei file oggetto (.o) a partire ai file sorgente (.c)
OBJ = $(SRC:.c=.o)

BONUS_OBJ = $(BONUS_SRC:.c=.o)

#regola principale per creare la libreria
all: $(NAME)

#creazione della libreria statica
$(NAME): $(OBJ)
	ar rc $@ $?

bonus: $(BONUS_OBJ)
	ar rc $(NAME) $?

#compilazione dei file sorgente
%.o: %.c
	$(CC) $(CFLAGS) -c $?

#pulizia dei file oggetto
clean:
	rm -f $(OBJ) $(BONUS_OBJ)

#rimozione di file oggetto e libreria
fclean: clean
	rm -f $(NAME)

#ricompilazione completa
re: fclean all

.PHONY: all clean fclean re
