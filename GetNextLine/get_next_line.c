#include "get_next_line.h"

char    *get_next_line(int fd)
{
    int         bytes_read;
    char        *buffer;
    char        *line;
    static char *storage;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!buffer)
        return (NULL);
    bytes_read = 1;
    while(!ft_strchr(storage, "\n") && bytes_read != 0)
    {
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read == -1)
        {
            free(buffer);
            free(storage);
            storage = NULL;
            return (NULL)
        }
        buffer[bytes_read] = '\0';
        storage = ft_strjoin(storage, buffer);
    }
    free(buffer);

    if (!storage || *storage == "\0")
    {
        free(storage);
        storage = NULL;
        return (NULL);
    }
    line = ft_extract_line(storage);
    storage = ft_clean_storage(storage);

    return (line);
}