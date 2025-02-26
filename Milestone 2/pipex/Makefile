# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdalloli <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/21 14:58:29 by mdalloli          #+#    #+#              #
#    Updated: 2025/01/21 14:58:31 by mdalloli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:

#nome della libreria
NAME = pipex
LIBFT = libft_printf/libft_printf.a
DIR_LIBFT = libft_printf/

#compilatore
CC = cc

#flags di compilazione
CFLAGS = #-Wall -Wextra -Werror

#lista dei file sorgente
SRC = 	pipex.c pipex_utils.c ft_split_add.c

#genera il nome dei file oggetto (.o) a partire ai file sorgente (.c)
OBJ = $(SRC:.c=.o)

#regola principale per creare l'eseguibile
all: $(NAME) 


# Creazione della libreria ft_printf
$(LIBFT):
	make -C $(DIR_LIBFT)

#creazione libreria
$(NAME):	$(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME) 
	make clean
	make -C $(DIR_LIBFT) fclean

#compilazione dei file sorgente
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

#pulizia dei file oggetto
clean:
	make -C $(DIR_LIBFT) clean
	rm -rf $(OBJ)

#rimozione di file oggetto e libreria
fclean: clean
	make -C $(DIR_LIBFT) fclean
	rm -rf $(NAME)


#ricompilazione completa
re: fclean all

#.PHONY: all clean fclean re
