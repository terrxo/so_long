CC = cc
CFLAGS = -Wall -Wextra

all:
			$(CC) $(CFLAGS) -c *.c ../ft_printf/libftprintf.a
			ar -rcs gnl.a *.o
			
clean:	
			rm -f *.o

fclean:	clean
			rm -f gnl.a

re:	fclean all

.PHONY:	all clean fclean re