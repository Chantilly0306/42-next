#include <stdlib.h>

int	*ft_range(int start, int end)
{
	int	*arr;
	int	i = 0;
	int	step;
	int	size;

	if (start <= end)
	{
		size = end - start + 1;
		step = 1;
	}
	else
	{
		size = start - end + 1;
		step = -1;
	}
	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (0);
	while (i < size)
	{
		arr[i] = start + (step * i);
		i++;
	}
	return (arr);
}
