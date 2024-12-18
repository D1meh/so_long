#include "basics.h"

int	split_len(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		i++;
	}
	return (i);
}
