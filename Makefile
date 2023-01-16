CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = ./src/*.c
OBJ = ./obj/*.o
NAME = so_long

all:
			$(MAKE) all -C ./ft_printf
			cd ./obj/ ; $(CC) $(CFLAGS) -Imlx -c ../$(SRC)
			$(CC) $(CFLAGS) $(OBJ) ./ft_printf/libftprintf.a ./mlx/libmlx.a -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
			
clean:	
			$(MAKE) clean -C ./ft_printf
			rm -f ./obj/*.o

fclean:	clean
			$(MAKE) fclean -C ./ft_printf
			rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
