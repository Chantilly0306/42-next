#include <stdio.h>
#include <stdlib.h>

void	fprime(int nb)
{
	int	i = 2;

	while (i <= nb)
	{
		if (nb % i == 0)
		{
			printf("%d", i);
			if (nb == i)
				return ;
			printf("*");
			nb /= i;
		}
		else
			i++;
	}
}

int	main(int argc, char **argv)
{
	int	nb;

	if (argc != 2)
		return (printf("/n"), 0);
	nb = atoi(argv[1]);
	if (nb == 1)
		return (printf("1/n"), 0);
	fprime(nb);
	printf("\n");
}
