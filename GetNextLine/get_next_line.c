#include "get_next_line.h"

void    clear_all(char **str)
{
    free(*str);
    *str = NULL;
}

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
    while(!ft_strchr(storage, '\n') && bytes_read != 0)
    {
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read == -1)
            return (clear_all(&buffer), clear_all(&storage), NULL);
        buffer[bytes_read] = '\0';
        storage = ft_strjoin(storage, buffer);
    }
    free(buffer);
    if (!storage || *storage == '\0')
        return (clear_all(&storage), NULL);
    line = ft_extract_line(storage);
    storage = ft_clean_line(storage);
    return (line);
}

/*
void	test_file(char *filename)
{
	int		fd;
	char	*line;
	int		line_count;

	printf("\n--- Read file: %s ---\n", filename);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror("Fail to open file");
		return ;
	}
	line_count = 1;
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("line %d: %s", line_count++, line);
		free(line);
	}
	close(fd);
}

void	test_stdin(void)
{
	char	*line;
	int		line_count;

	printf("\n--- Type some words and enter. Ctrl+D for exit ---\n");
	line_count = 1;
	while ((line = get_next_line(0)) != NULL)
	{
		printf("line %d: %s", line_count++, line);
		free(line);
	}
}

int	main(void)
{
	test_file("README.md");
	// test_file("does_not_exist.txt");
	// test_stdin();
	return (0);
}
*/