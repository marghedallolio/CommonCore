

.SILENT:

# nome della libreria
NAME = push_swap
LIBFT = libft/libft.a
DIR_LIBFT = libft/

# compilatore e flags di compilazione 
CC = cc
CFLAGS = -Wall -Werror -Wextra

# lista dei file sorgente
SRC = main.c push.c reverse_rotate.c rotate.c sorting.c swap.c utils.c \
	errors.c init.c index.c funzioni_liste.c radix_sort.c simple_sort.c

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