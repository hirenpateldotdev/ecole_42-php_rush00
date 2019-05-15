#include "get_next_line.h"

int     ft_read(int fd, char *buffer)
{
    int ret = read(fd, buffer, BUFF_SIZE);
    buffer[ret] = '\0';
    return ret;
}

void ft_strappend(char **str, char *sub)
{
    char *temp = ft_strjoin(*str, sub);
    free(*str);
    *str = temp;
}

int ft_strchrn(char *str, char c)
{
    int i = 0;
    while (str[i] != c && str[i] != '\0')
        i++;
    return i;
}
void ft_strtrim_todest(char **dest, char **src, int start, int end)
{
    *dest = ft_strsub(*src, start, end);
    char *temp = ft_strdup(*src + end + 1);
    free(*src);
    *src = temp;
    if (src[0] == '\0')
        ft_strdel(&*src);
}

int             get_next_line(const int fd, char **line)
{
    static char  *hashmap[MAX_FD];
    char        buffer[BUFF_SIZE + 1];
    int         ret;
    int         end;

    if ( fd < 0 || MAX_FD < fd || line == NULL || read(fd, buffer, 0) < 0)
        return -1;
    if (hashmap[fd] == NULL)
        hashmap[fd] = ft_strnew(1);
    while ( ft_strchr(hashmap[fd], '\n') == 0 && (ret = ft_read(fd, buffer) > 0))
        ft_strappend(&hashmap[fd], buffer);
    if ( ret == 0 && (hashmap[fd] == NULL || hashmap[fd][0] == '\0'))
        return 0;
    end = ft_strchrn(hashmap[fd], '\n');
    if (hashmap[fd][end] == '\n')
        ft_strtrim_todest(line, &hashmap[fd], 0 , end);
    else
    {
        if (ret == BUFF_SIZE)
            return get_next_line(fd, line);
        *line = ft_strdup(hashmap[fd]);
        ft_strdel(&hashmap[fd]);
    }
    return 1;
}