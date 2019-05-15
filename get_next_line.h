#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#define BUFF_SIZE 10000000
#define MAX_FD 4096

#include "unistd.h"
#include "./libft/libft.h"

int		get_next_line(const int fd, char **line);

#endif