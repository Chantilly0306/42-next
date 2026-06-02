#include "libft.h"

int	ft_strlen(char *s)
{
	int	len;

	len = 0;
	while (*s++)
		len++;
	return (len);
}

int ft_strlcat(char *dst, char *src, int dstsize)
{

}

int main(void)
{
    char	str1[] = "Hello World!";
	char	str2[] = "Bonjour tout le monde";

    ft_strlcat(str1, str2, 12);
    printf("%s\n", str1);
}
