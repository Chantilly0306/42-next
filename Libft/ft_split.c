/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsilin <hsilin@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 15:37:36 by hsilin            #+#    #+#             */
/*   Updated: 2026/06/11 18:41:51 by hsilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_word(char const *s, char c)
{
	int	i;
	int	word_count;

	i = 0;
	word_count = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == '\0' || s[i + 1] == c))
			word_count++;
		i++;
	}
	return (word_count);
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

char	*fill_word(char const *s, char c, int *i)
{
	int		len;
	char	*str;

	len = 0;
	while (s[*i] == c)
		(*i)++;
	while (s[*i] != c && s[*i] != '\0')
	{
		len++;
		(*i)++;
	}
	*i -= len;
	str = ft_substr(s, (unsigned int)*i, len);
	*i += len;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		i;
	int		word;
	int		word_count;

	if (!s)
		return (NULL);
	word_count = count_word(s, c);
	arr = malloc(sizeof(char *) * (word_count + 1));
	if (!arr)
		return (NULL);
	i = 0;
	word = 0;
	while (word < word_count)
	{
		arr[word] = fill_word(s, c, &i);
		if (!arr[word])
			return (free_arr(arr), NULL);
		word++;
	}
	arr[word] = NULL;
	return (arr);
}
/*
int	main(void)
{
	int i = 0;
	char	**result = ft_split(".Hello..World.", '.');

	if (!result)
		return (0);
	while (result[i])
	{
		printf("%s\n", result[i]);
		i++;
	}
	free_arr(result);
}
*/
