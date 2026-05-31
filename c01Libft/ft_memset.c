#include "libft.h"

void	*ft_memset(void *b, int c, int len)
{
	int				i;
	unsigned char	*p;

	p = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		p[i] = (unsigned int)c;
		i++;
	}
	return (b);
}
/*
int	main(void)
{
    char	str[] = "Hello World!";

    ft_memset(str, 'X', 5);
    printf("%s\n", str);
}
*/