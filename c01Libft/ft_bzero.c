#include "libft.h"

void	ft_bzero(void *b, int len)
{
	int				i;
	unsigned char	*p;

	p = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		p[i] = 0;
		i++;
	}
}
/*
int	main(void)
{
    char	str[] = "Hello World!";

    ft_bzero(str, 5);
    printf("%s\n", str);
}
*/