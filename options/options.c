#include <unistd.h>

int		options(char *str, int *aopts)
{
	if (*str != '-')
		return (0);
	str++;
	if (!*str)
		return (0);
	while (*str)
	{
		if (*str < 'a' || *str > 'z')
			return (0);
		*aopts |= 1 << (*str - 'a');
		str++;
	}
	return (1);
}

int		main(int argc, char *argv[])
{
	int		opts;
	int		i;

	opts = 0;
	i = 1;
	while (i < argc)
	{
		if (!options(argv[i], &opts))
		{
			write(1, "Invalid Option\n", 15);
			return (0);
		}
		i++;
	}
	if (opts == 0 || opts & (1 << ('h' - 'a')))
	{
		write(1, "options: abcdefghijklmnopqrstuvwxyz\n", 36);
	}
	else
	{
		i = 32;
		while (i-- > 0)
		{
			if (opts & (1 << i))
				write(1, "1", 1);
			else
				write(1, "0", 1);
			if (i > 0 && i % 8 == 0)
				write(1, " ", 1);
		}
		write(1, "\n", 1);
	}
	return (0);
}
