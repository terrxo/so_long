CC = cc
CFLAGS = -Wall -Wextra
SRC = ./src/*.c
OBJ = ./obj/*.o

all:
			$(MAKE) all -C ./ft_printf
			$(MAKE) all -C ./get_next_line
			cd ./obj/ ; $(CC) $(CFLAGS) -Imlx -c ../$(SRC) -g
			$(CC) $(CFLAGS) $(OBJ) ./ft_printf/libftprintf.a ./get_next_line/gnl.a ./mlx/libmlx.a -Lmlx -lmlx -framework OpenGL -framework AppKit -o program.out -g
			
clean:	
			$(MAKE) clean -C ./ft_printf
			$(MAKE) clean -C ./get_next_line
			rm -f ./obj/*.o

fclean:	clean
			$(MAKE) fclean -C ./ft_printf
			$(MAKE) fclean -C ./get_next_line
			rm -f program.out

re:	fclean all

.PHONY:	all clean fclean re
