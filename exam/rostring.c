#include <unistd.h>

int	is_space(char c)
{
	return (c == ' ' || c == '\t');
}

int	main(int argc, char **argv)
{
	int		breakpoint;
	int		endpoint;
	int		first = 1;
	int		put_space = 0;
	int		i = 0;
	char	*s;

	if (argc < 2)
		return (write(1, "\n", 1), 0);
	s = argv[1];
	while (s[i])
	{
		while (is_space(s[i]))
			i++;
		if (first && s[i] && !is_space(s[i]))
		{
			breakpoint = i;
			while (s[i] && !is_space(s[i]))
				i++;
			endpoint = i - 1;
			first = 0;
		}
		while (s[i] && !is_space(s[i]))
		{
			write(1, &s[i], 1);
			put_space = 1;
			i++;
		}
		if (put_space)
			write(1, " ", 1);
	}
	while (first == 0 && breakpoint <= endpoint)
		write(1, &s[breakpoint++], 1);
	write(1, "\n", 1);
}
