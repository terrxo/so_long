#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <stdlib.h>
#include "../ft_printf/libft/libft.h"

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1000
#endif

char *get_next_line(int fd);
char *ft_read_to_left_str(int fd, char *left_str);
char *ft_get_line(char *left_str);
char *ft_new_left_str(char *left_str);

#endif
