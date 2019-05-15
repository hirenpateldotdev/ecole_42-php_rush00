#include "get_next_line.h"
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>


int         main(int av, char **ac)
{
    char    *line;
    int     fd;

    fd = open(ac[1],O_RDONLY);
    while (get_next_line(fd,&line) == 1)
        printf("%s\n",line);
    close(fd);
    return 0;
}



























































