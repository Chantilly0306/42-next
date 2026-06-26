#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s != (char)c)
	{
		if (*s == '\0')
			return (NULL);
		s++;
	}
	return ((char *)s);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	if (!s2)
		return (s1);
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (free(s1), NULL);
	i = 0;
	j = 0;
	while (s1 && s1[j])
		str[i++] = s1[j++];
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	return (free(s1), str);
}

char	*ft_extract_line(char *storage)
{
	int		i;
	char	*line;

	if (!storage || *storage == '\0')
		return (NULL);
	i = 0;
	while (storage[i] && storage[i] != '\n')
		i++;
	if (storage[i] == '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (storage[i] && storage[i] != '\n')
	{
		line[i] = storage[i];
		i++;
	}
	if (storage[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_clean_line(char *storage)
{
	char	*residual;
	char	*new_res;
	int		len;

	residual = ft_strchr(storage, '\n');
	if (!residual)
		return (NULL);
	len = ft_strlen(residual);
	if (len <= 1)
		return (NULL);
	new_res = malloc(sizeof(char) * len);
	if (!new_res)
		return (NULL);
	new_res[--len] = '\0';
	while (--len >= 0)
		new_res[len] = residual[len + 1];
	free(storage);
	return (new_res);
}
char	*ft_clean_line(char *storage)
{
	char	*new_res;
	int		i;
	int		j;

	i = 0;
	while (storage[i] && storage[i] != '\n')
		i++;
	if (!storage[i])
	{
		free(storage);
		return (NULL);
	}
	new_res = malloc(sizeof(char) * (ft_strlen(storage) - i));
	if (!new_res)
		return (free(storage), NULL);
	i++; // 跳過 '\n'
	j = 0;
	while (storage[i])
		new_res[j++] = storage[i++];
	new_res[j] = '\0';
	free(storage);
	return (new_res);
}
