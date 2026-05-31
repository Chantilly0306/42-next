#include "libft.h"

void	*ft_memcpy(void *dst, void *src, int n)
{
	int				i;
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	if (!dst && !src)
		return (NULL);
	ptr1 = (unsigned char *)dst;
	ptr2 = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		ptr1[i] = ptr2[i];
		i++;
	}
	return (dst);
}

int	main(void)
{
    char	str1[] = "Hello World!";
	char	str2[] = "Bonjour tout le monde";

    ft_memcpy(str1, str2, 7);
    printf("%s\n", str1);
}
