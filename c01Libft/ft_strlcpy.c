#include "libft.h"

int	ft_strlen(char *s)
{
	int	len;

	len = 0;
	while (*s++)
		len++;
	return (len);
}

int ft_strlcpy(char *dst, char *src, int dstsize)
{
    int    i;

    if (dstsize == 0)
        return (ft_strlen(src));
    i = 0;
    while (src[i] && i < dstsize - 1)
    {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
    return (ft_strlen(src));
}
/*
int main(void)
{
    char	str1[] = "Hello World!";
	char	str2[] = "Bonjour tout le monde";

    ft_strlcpy(str1, str2, 12);
    printf("%s\n", str1);
}
*/