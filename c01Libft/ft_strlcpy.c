#include "libft.h"

size_t  ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s++)
		len++;
	return (len);
}

size_t  ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
    size_t    i;

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