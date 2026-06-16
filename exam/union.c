#include <unistd.h>

int ft_strlen(char *s)
{
    int len = 0;

    while (*s++)
        len++;
    return (len);
}

int cmp(int i, char *s1, char *s2, int len)
{
    int j = 0;

    if (i < len)
    {
        while (j < i)
        {
            if (s1[j] == s1[i])
                return (0);
            j++;
        }
    }
    else
    {
        while (j < i)
        {
            if ((j < len && s1[j] == s2[i - len]) 
                || (j >= len && s2[j - len] == s2[i - len]))
                return (0);
            j++;
        }
    }
    return (1);
}

int main(int argc, char **argv)
{
    int i = 0;
    int len;

	if (argc != 3)
		return (write(1, "\n", 1), 0);
	len = ft_strlen(argv[1]);
    while (argv[1][i])
    {
        if (cmp(i, argv[1], argv[2], len))
            write(1, &argv[1][i], 1);
        i++;
    }
    while (argv[2][i - len])
    {
        if (cmp(i, argv[1], argv[2], len))
            write(1, &argv[2][i - len], 1);
        i++;
    }
    write(1, "\n", 1);
}

