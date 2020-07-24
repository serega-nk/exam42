#include "unistd.h"

int		print(char **addr, int p)
{
	char	*ptr;

	ptr = *addr;
	while (*ptr == ' ' || *ptr == '\t')
		ptr++;
	*addr = ptr;
	if (*ptr)
	{
		while (*ptr && *ptr != ' ' && *ptr != '\t')
		{
			if (p > 0)
				write(1, ptr, 1);
			ptr++;
		}
		if (ptr > *addr)
		{
			*addr = ptr;
			if (p == 1)
				write(1, " ", 1);
			return (1);
		}
	}	
	return (0);	
}

int		main(int argc, char *argv[])
{
	char	*str;
	
	if (argc == 2)
	{
		str = argv[1];
		print(&str, 0);
		while (print(&str, 1))
			;
		str = argv[1];
		print(&str, 2);
	}
	write(1, "\n", 1);
	return (0);
}
