#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s++)
		len++;
	return (len);
}
/*
int	main(void)
{
	printf("strlen: %zu\n", ft_strlen("e1/0\0ji"));
}
*/