#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i = 1;

	if (argc != 2)
		return (write(1, "\n", 1));
	int	len = ft_strlen(argv[1]);
	int	nb = ft_atoi(argv[1]);
	while (i <= 9)
	{
		write(1, &i, 1);
		write(1, " x ", 3);
		write(1, &argv[1], len);
		write(1, " = ", 3);
		ptnbr(i * nb);
		write(1, "\n", 1);
		i++;
	}
}
