#include <stdio.h>

char	*ft_strrev(char *str)
{
	int		i;
	int		len;
	char	tmp;

	//if (!str)
	//	return (NULL);
	len = 0;
	while (str[len] != '\0')
		len++;
	i = 0;
	while (i < len / 2)
	{
		tmp = str[i];
		str[i] = str[len - 1 - i]; 
		str[len - 1 - i] = tmp;
		i++;
	}
	return (str);
}

int main(void)
{
	char test1[] = "Hello";
	char test2[] = "123456";
	char test3[] = "A";
	char test4[] = "";

	printf("%s\n", ft_strrev(test1));
	printf("%s\n", ft_strrev(test2));
	printf("%s\n", ft_strrev(test3));
	printf("%s\n", ft_strrev(test4));

	return (0);
}
