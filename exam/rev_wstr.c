#include <unistd.h>
#include <stdlib.h>

int	delimiter(char c)
{
	return (c == '\0' || c == ' ' || c == '\t');
}

int	count_word(char *s)
{
	int	i = 0;
	int	word = 0;

	while (s[i])
	{
		if (!delimiter(s[i]) && delimiter(s[i + 1]))
			word++;
		i++;
	}
	return (word);
}

int	ft_strlen(char *s)
{
	int	len = 0;

	while (*s++)
		len++;
	return (len);
}

char	*fill(char *s, int *j)
{
	char	*str;
	int		len = 0;
	int		k = 0;

	while (delimiter(s[*j]))
		(*j)++;
	while (!delimiter(s[(*j)]))
	{
		(*j)++;
		len++;
	}
	*j -= len;
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (!delimiter(s[*j]))
	{
		str[k] = s[*j];
		k++;
		(*j)++;
	}
	return (str);
}

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	main(int argc, char **argv)
{
	char	**res;
	char	*s;
	int		len;
	int		word;
	int		i = 0;
	int		j = 0;

	if (argc != 2)
		return (write(1, "\n", 1), 0);
	s = argv[1];
	len = ft_strlen(s);
	word = count_word(s);
	if (word < 2)
		return (write(1, s, len), 0);
	res = malloc(sizeof(char *) * (word + 1));
	if (!res)
		return (0);
	res[word] = NULL;
	while (i < word)
	{
		res[i] = fill(s, &j);
		if (!res[i])
			return (free_arr(res), 0);
		i++;
	}
	while (--i >= 0)
	{
		write(1, res[i], ft_strlen(res[i]));
		if (i == 0)
			return (write(1, "\n", 1), free_arr(res), 0);
		write(1, " ", 1);
	}
}
