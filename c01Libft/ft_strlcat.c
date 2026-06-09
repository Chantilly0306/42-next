#include "libft.h"

size_t  ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s++)
		len++;
	return (len);
}

int ft_strlcat(char *dst, char *src, int dstsize)
{
	int	dst_len;
	int	src_len;
	int	i;
}

int main(void)
{
    char	str1[] = "Hello World!";
	char	str2[] = "Bonjour tout le monde";

    ft_strlcat(str1, str2, 12);
    printf("%s\n", str1);
}
