#include "libft.h"

int	ft_isalnum(int c)
{
	return ((c >= 65 && c <= 90) || (c >= 97 && c <= 122) ||
         (c >= 48 && c <= 57));
}
/*
int	main(int argc, char **argv)
{
	printf("%d\n", ft_isalnum('U'));
}
*/