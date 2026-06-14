/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsilin <hsilin@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 15:52:14 by hsilin            #+#    #+#             */
/*   Updated: 2026/06/09 15:52:53 by hsilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != (char)c)
	{
		if (*s == '\0')
			return (NULL);
		s++;
	}
	return ((char *)s);
}
/*
int main()
{
    char *str = "Hello, World!";
    char c = '\0';
    char *result = ft_strchr(str, c);

    if (result)
        printf("Character '%c' found at position: %ld\n", c, result - str);
    else
        printf("Not found\n");
    return 0;
}
*/