#include <stdlib.h>

int	is_delimiter(char c)
{
	return (s[i] == ' ' || s[i] == '\t' || s[i] == '\n' || s[i] = '\0');
}

int	count_word(char *s)
{
	int	i = 0;
	int	word = 0;

	while (s[i])
	{
		if (!is_delimiter(s[i]) && is_delimiter(s[i + 1]))
			word++;
		i++;
	}
	return (word);
}

char	**ft_split(char *str)
{
	char	**res;
	int		word;
	int		i;

	if (!str)
		return (NULL);
	word = count_word(str);
	res = malloc(sizeof(char *) * (word + 1);
	if (!res)
		return (NULL);
	res[word] = NULL;
	while (i < word)
	{

	}
}
