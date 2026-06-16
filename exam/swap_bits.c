void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

unsigned char	swap_bits(unsigned char octet)
{
	return ((octet % 16) * 16 + octet / 16);
}
