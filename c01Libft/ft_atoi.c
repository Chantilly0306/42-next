#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	flag;
	int	res;

	i = 0;
	flag = 1;
	res = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			flag = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10 + (nptr[i] - '0');
		i++;
	}
	return (res * flag);
}
/*
int	main(void)
{
	printf("%d\n", ft_atoi("+75689"));
	printf("%d\n", ft_atoi("-12a3"));
	printf("%d\n", ft_atoi(" \n+432"));
	printf("%d\n", ft_atoi("a+123"));
	printf("%d\n", ft_atoi("--123"));
}
*/