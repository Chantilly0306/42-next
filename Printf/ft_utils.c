#include "ft_printf.h"

int	ft_print_str(char *str)
{
	int	i;

	if (!str)
		return (write(1, "(null)", 6));
	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
	return (i);
}

int	ft_print_nbr(int nbr)
{
	int		len;
	char	c;

	if (nbr == -2147483648)
		return (write(1, "-2147483648", 11), 11);
	len = 0;
	if (nbr < 0)
	{
		len += write(1, "-", 1);
		nbr = -nbr;
	}
	if (nbr >= 10)
		len += ft_print_nbr(nbr / 10);
	c = '0' + nbr % 10;
	len += write(1, &c, 1);
	return (len);
}

int	ft_print_unsigned_int(unsigned int nbr)
{
	int		len;
	char	c;

	len = 0;
	if (nbr >= 10)
		len += ft_print_unsigned_int(nbr / 10);
	c = '0' + nbr % 10;
	len += write(1, &c, 1);
	return (len);
}

int	ft_print_hex(unsigned long nbr, char *base)
{
	int	len;

	len = 0;
	if (nbr >= 16)
		len += ft_print_hex(nbr / 16, base);
	len += write(1, &base[nbr % 16], 1);
	return (len);
}

int	ft_print_ptr(void *ptr)
{
	int	len;

	if (!ptr)
		return (write(1, "0x0", 3));
	write(1, "0x", 2);
	len = 2;
	len += ft_print_hex((unsigned long)ptr, "0123456789abcdef");
	return (len);
}
