# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdalloli <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/12 10:52:28 by mdalloli          #+#    #+#              #
#    Updated: 2025/02/12 10:52:30 by mdalloli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:

#nome dell'eseguibile
NAME = fractol

MLX = mlx/libmlx.a
DIR_MLX = mlx/
LIBFT = libft_printf/libft_printf.a
DIR_LIBFT = libft_printf/

#Compilatore e flags di compilazione
CC = cc
CFLAGS = -Wall -Werror -Wextra -O3
MLXFLAGS = -Lmlx -lXext -lm -lmlx -lX11

#File sorgenti
SRC = main.c utils.c julia.c mandelbrot.c draw.c events.c fractol.c

#genera il nome dei file oggetto (.o) a partire ai file sorgente (.c)
OBJ = $(SRC:.c=.o)

#regola principale per creare l'eseguibile
all: $(NAME)

#creazione della libreria mlx
$(MLX):
	make -C $(DIR_MLX)

# Creazione della libreria libft_printf
$(LIBFT):
	make -C $(DIR_LIBFT)

#creazione libreria
$(NAME): $(OBJ) $(MLX) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(MLX) $(LIBFT) -o $(NAME) $(MLXFLAGS)

#compilazione dei file sorgente
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

#pulizia dei file oggetto
clean:
	make -C $(DIR_MLX) clean
	make -C $(DIR_LIBFT) clean
	rm -rf $(OBJ)

#rimozione di file oggetto e libreria
fclean: clean
	rm -rf $(NAME)

#ricompilazione completa
re: fclean all