# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdalloli <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/24 14:20:31 by mdalloli          #+#    #+#              #
#    Updated: 2025/02/24 14:20:33 by mdalloli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

./SILENT:

# nome della libreria
NAME = push_swap 

# compilatore e flags di compilazione 
CC = cc
CFLAGS = -Wall -Werror -Wextra

# lista dei file sorgente
SRC = main.c operations.c parsing.c sorting.c stack_utils.c

# genera il nome dei file oggetto (.o) a partire dai file sorgente (.c)
OBJ = $(SRC:.c=.o)

# regola principale per creare l'eseguibile
all: $(NAME)

# creazione libreria
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

# compilazione dei file oggetto
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# pulizia dei file oggetto 
clean: 
	rm -f $(OBJ)

# rimozione dei file oggetto e libreria
fclean: clean
	rm -f $(NAME)
	
# ricompilazione completa
re: fclean all