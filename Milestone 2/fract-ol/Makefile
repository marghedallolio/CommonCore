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
FT_PRINTF = ft_printf/ft_printf.a
DIR_FT_PRINTF = ft_printf/

#Compilatore e flags di compilazione
CC = cc
CFLAGS = -Wall -Werror -Wextra 
MLXFLAGS = -Lmlx -lXext -lm -lmlx -lX11

#File sorgenti
SRC = main.c utils.c julia.c mandelbrot.c draw.c events.c fractals.c

#genera il nome dei file oggetto (.o) a partire ai file sorgente (.c)
OBJ = $(SRC:.c=.o)

#regola principale per creare l'eseguibile
all: $(NAME)

#creazione della libreria mlx
$(MLX):
	make -C $(DIR_MLX)

# Creazione della libreria ft_printf
$(FT_PRINTF):
	make -C $(DIR_FT_PRINTF)

#creazione libreria
$(NAME): $(OBJ) $(MLX) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(OBJ) $(MLX) $(FT_PRINTF) -o $(NAME) $(MLXFLAGS)
	make clean
	make -C $(DIR_MLX) fclean
	make -C $(DIR_FT_PRINTF) fclean

#compilazione dei file sorgente
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

#pulizia dei file oggetto
clean:
	make -C $(DIR_MLX) clean
	make -C $(DIR_FT_PRINTF) clean
	rm -rf $(OBJ)

#rimozione di file oggetto e libreria
fclean: clean
	make -C $(DIR_MLX) fclean
	make -C $(DIR_FT_PRINTF) fclean
	rm -rf $(NAME)

#ricompilazione completa
re: fclean all

