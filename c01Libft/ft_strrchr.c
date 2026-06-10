#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;

	len = ft_strlen(s);
	s += len;
	if ((char)c == '\0')
		return ((char *)s);
	while (len-- > 0)
	{
		s--;
		if (*s == (char)c)
			return ((char *)s);
	}
	return (NULL);
}
/*
int main()
{
    char *str = "Hello, World!";
    char c = 'o';
    char *result = ft_strrchr(str, c);

    if (result)
        printf("Character '%c' found at position: %ld\n", c, result - str);
    else
        printf("Not found\n");
    return 0;
}
*/
