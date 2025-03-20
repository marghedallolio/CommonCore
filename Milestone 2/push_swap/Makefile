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

.SILENT:

# nome della libreria
NAME = push_swap
LIBFT = libft_printf/libft_printf.a
DIR_LIBFT = libft_printf/

# compilatore e flags di compilazione 
CC = cc
CFLAGS = -Wall -Werror -Wextra

# lista dei file sorgente
SRC = main.c push.c reverse_rotate.c rotate.c sorting.c swap.c utils.c \
	errors.c init.c target_cost.c stack_utils.c

# genera il nome dei file oggetto (.o) a partire dai file sorgente (.c)
OBJ = $(SRC:.c=.o)

# regola principale per creare l'eseguibile
all: $(NAME)

#creazione della libreria libft_printf
$(LIBFT):
	make -C $(DIR_LIBFT)

# creazione libreria
$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

# compilazione dei file oggetto
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# pulizia dei file oggetto 
clean:
	make -C $(DIR_LIBFT) clean
	rm -rf $(OBJ)

# rimozione dei file oggetto e libreria
fclean: clean
	make -C $(DIR_LIBFT) fclean
	rm -f $(NAME)
	
# ricompilazione completa
re: fclean all