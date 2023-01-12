CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = ./*.c
OBJ = ./*.o

all:
			$(CC) $(CFLAGS) -c $(SRC)
			ar -rcs gnl.a  $(OBJ)
			
clean:	
			rm -f ./*.o

fclean:	clean
			rm -f gnl.a

re:	fclean all

.PHONY:	all clean fclean re
