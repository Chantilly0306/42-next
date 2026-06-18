void	sort_int_tab(int *tab, unsigned int size)
{
	unsigned int	i = 0;
	unsigned int	j;
	int				tmp;

	if (size <= 1)
		return ;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - 1 - i)
		{
			if (tab[j] > tab[j + 1])
			{
				tmp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}
