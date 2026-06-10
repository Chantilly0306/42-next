#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;

	str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (str[i] == (unsigned char)c)
			return ((void *)(s + i));
		i++;
	}
	return (NULL);
}
/*
int main()
{
    char str[] = "Hello, World!";
    char c = 'l';
    char *result = ft_memchr(str, c, 5);
    
    if (result)
        printf("Character '%c' found at position: %ld\n", c, result - str);
    else
        printf("Not found\n");
}
*/
