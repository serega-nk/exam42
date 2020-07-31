#include "unistd.h"

int		options(char *str, int *aopt)
{
	if (*str != '-')
		return (1);
	str++;
	while (*str)
	{
		if (*str == 'h')
		{
			write(1, "options: abcdefghijklmnopqrstuvwxyz\n", 36);
			return (0);
		}
		if (*str < 'a' || *str > 'z')
		{
			write(1, "Invalid Option\n", 15);
			return (0);
		}
		*aopt = *aopt | (1 << (*str - 'a'));
		str++;
	}
	return (1);
}

int		main(int argc, char *argv[])
{
	int	res;
	int	index;

	if (argc == 1)
	{
		write(1, "options: abcdefghijklmnopqrstuvwxyz\n", 36);
		return (0);
	}
	res = 0;
	index = 1;
	while (index < argc)
	{
		if (!options(argv[index], &res))
			return (0);
		index++;
	}
	index = 32;
	while (index > 0)
	{
		index--;
		write(1, res & (1 << index) ? "1" : "0", 1);
		if (index && index % 8 == 0)
			write(1, " ", 1);
	}
	write(1, "\n", 1);
}
