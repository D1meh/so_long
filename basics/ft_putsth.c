#include "basics.h"

void	ft_putnbr(int n)
{
	long int	nb;
	char		c;

	nb = n;
	if (n < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		c = (nb % 10) + '0';
		write(1, &c, 1);
	}
	else
	{
		c = nb + '0';
		write(1, &c, 1);
	}
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}
