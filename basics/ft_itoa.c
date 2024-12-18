#include "basics.h"
#include "../so_long_bonus.h"

static int	base10(long long int n)
{
	int	base;

	if (n == 0)
		return (1);
	base = 0;
	while (n != 0)
	{
		n /= 10;
		base++;
	}
	return (base);
}

static char	*alloc_nb(long long int n, int *size)
{
	char	*numb;

	*size = base10(n) + 1;
	if (n < 0)
	{
		numb = (char *)malloc(sizeof(char) * (*size) + 1);
		if (!numb)
			return (NULL);
		numb[0] = '-';
	}
	else
	{
		numb = (char *)malloc(sizeof(char) * *size);
		if (!numb)
			return (NULL);
	}
	return (numb);
}

static	char	*rempl_tab(long long int n, char *numb)
{
	int				i;
	unsigned int	nb;

	i = base10(n);
	if (n < 0)
	{
		i++;
		nb = n * -1;
	}
	else
		nb = n;
	numb[i] = '\0';
	i--;
	while (i >= 0 && numb[i] != '-')
	{
		numb[i] = (nb % 10) + '0';
		nb /= 10;
		i--;
	}
	return (numb);
}

char	*ft_itoa(long long int n)
{
	int			size;
	char		*numb;

	numb = alloc_nb(n, &size);
	if (!numb)
		return (NULL);
	if (n == 0)
	{
		numb[0] = '0';
		numb[1] = '\0';
	}
	else
		numb = rempl_tab(n, numb);
	return (numb);
}
