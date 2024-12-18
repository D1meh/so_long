#include "basics.h"

int	ft_only1(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] != '1')
			return (0);
		i++;
	}
	return (1);
}
