#include "../so_long.h"

void	split_error(char **split, int code)
{
	free_split(split);
	print_error(code);
}

void	print_error(int code)
{
	write(2, "Error\n", 6);
	if (code == 1)
		write(2, "Incorrect number of arguments\n", 30);
	else if (code == 2)
		write(2, "Not a .ber file\n", 16);
	else if (code == 3)
		write(2, "Incorrect file\n", 15);
	else if (code == 4)
		write(2, "Empty map\n", 10);
	else if (code == 5)
		write(2, "Map isn't rectangular\n", 22);
	else if (code == 6)
		write(2, "Map isn't surrounded by walls\n", 30);
	else if (code == 7)
		write(2, "Bad character in map description\n", 33);
	else if (code == 8)
		write(2, "Missing exit\n", 13);
	else if (code == 9)
		write(2, "Missing collectibles\n", 21);
	else if (code == 10)
		write(2, "Missing starting position\n", 26);
	else if (code == 11)
		write(2, "Too many starting position\n", 27);
	exit(code);
}
