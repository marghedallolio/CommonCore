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

#nome della libreria
NAME = pipex.a
FT_PRINTF = ft_printf/ft_printf.a
DIR_FT_PRINTF = ft_printf/
GET_NEXT_LINE = get_next_line/get_next_line.a
DIR_GET_NEXT_LINE = get_next_line/

#compilatore
CC = cc

#flags di compilazione
CFLAGS = -Wall -Wextra -Werror

#lista dei file sorgente
SRC = 	pipex.c pipex_utils.c ft_split_add.c \
	get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

#genera il nome dei file oggetto (.o) a partire ai file sorgente (.c)
OBJ = $(SRC:.c=.o)

#regola principale per creare l'eseguibile
all: $(NAME) $(FT_PRINTF)
	$(CC) pipex.c $(NAME) $(FT_PRINTF) $(CFLAGS) -o "pipex"
	@$(MAKE) fclean -C $(DIR_FT_PRINTF)
	@make fclean

# Creazione della libreria ft_printf
$(FT_PRINTF):
	$(MAKE) -C $(DIR_FT_PRINTF)

$(NAME):	$(OBJ)
	@ar rcs $(NAME) $(OBJ)

#compilazione dei file sorgente
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

#pulizia dei file oggetto
clean:
	rm -rf $(OBJ)

#rimozione di file oggetto e libreria
fclean: clean
	rm -rf $(NAME)


#ricompilazione completa
re: fclean all

#.PHONY: all clean fclean re
