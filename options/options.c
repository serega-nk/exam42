#include "unistd.h"

void	ft_putchar(char ch)
{
	write(1, &ch, 1);
}

void	ft_putstr(const char *str)
{
	if (str)
	{
		while (*str)
		{
			ft_putchar(*str);
			str++;
		}
	}
}

void	ft_putopt(int opt)
{
	int		i;

	i = 32;
	while (i > 0)
	{
		i--;
		ft_putchar(opt & (1 << i) ? '1' : '0');
		if (i > 0 && i % 8 == 0)
			ft_putchar(' ');
	}
}

int		options(char *s, int *aopt)
{
	if (*s == '-')
	{
		s++;
		while (*s)
		{
			if (*s < 'a' || *s > 'z')
				return (-1);
			if (*s == 'h')
				return (0);
			*aopt |= (1 << (*s - 'a'));
			s++;
		}
	}	
	return (1);	
}

int		main(int argc, char *argv[])
{
	int	res;
	int	opt;
	int	index;

	res = 0;
	opt = 0;
	index = 1;
	while (index < argc)
	{
		if ((res = options(argv[index], &opt)) != 1)
			break ;
		index++;
	}
	if (res == -1)
		ft_putstr("Invalid Option");
	else if (res == 0)
		ft_putstr("options: abcdefghijklmnopqrstuvwxyz");
	else
		ft_putopt(opt);
	ft_putchar('\n');
	return (0);
}
