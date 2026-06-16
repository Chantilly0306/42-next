#include <stdlib.h>
#include <stdio.h>

int	is_delimiter(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\0');
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

int	count_c(char *s, int j)
{
	int	len = 0;

	while (!is_delimiter(s[j++]))
		len++;
	return (len);
}

char	*str_cpy(char *s, int j, int len)
{
	char	*new;
	int		k = 0;

	if (!s)
		return (NULL);
	new = malloc(len + 1);
	if (!new)
		return (NULL);
	while (k < len)
		new[k++] = s[j++];
	new[k] = '\0';
	return (new);
}

char	**ft_split(char *str)
{
	char	**res;
	int		word;
	int		len;
	int		i = 0;
	int		j = 0;

	if (!str)
		return (NULL);
	word = count_word(str);
	res = malloc(sizeof(char *) * (word + 1));
	if (!res)
		return (NULL);
	res[word] = NULL;
	while (i < word)
	{
		if (!is_delimiter(str[j]))
		{
			len = count_c(str, j);
			res[i] = str_cpy(str, j, len);
			j += len;
			i++;
			continue ;
		}
		j++;
	}
	return (res);
}

int	main(void)
{
	int	i = 0;
	char	**result = ft_split("abc\ndef\t ghi ");

	while (result[i])
	{
		printf("%s\n", result[i]);
		i++;
	}
}
