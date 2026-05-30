#include "libft.h"

int	ft_strlen(char *s)
{
	int	len;

	len = 0;
	while (*s++)
		len++;
	return (len);
}
/*
int	main(void)
{
	printf("strlen: %d\n", ft_strlen("e1/0\0ji")); // =4
}
*/