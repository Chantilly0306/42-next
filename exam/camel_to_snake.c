#include <unistd.h>

int	main(int argc, char **argv)
{
	int		i = 0;
	char	c;

	if (argc != 2)
		return (write(1, "\n", 1), 0);
	while (argv[1][i])
	{
		c = argv[1][i];
		if (c >= 'A' && c <= 'Z')
		{
			write(1, "_", 1);
			c += 32;
			write(1, &c, 1);
		}
		else
			write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
}
