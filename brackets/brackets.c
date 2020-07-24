#include <unistd.h>

int		brackets(char *str)
{
	char	stack[1000];
	int		index;

	index = 0;
	stack[index] = '\0';
	while (*str)
	{
		if (*str == '(' || *str == '[' || *str == '{')
		{
			if (++index >= 1000)
				return (0);
			stack[index] = *str;
		}
		else if (
			(*str == ')' && stack[index] == '(') ||
			(*str == ']' && stack[index] == '[') ||
			(*str == '}' && stack[index] == '{'))
			--index;
		else if (*str == ')' || *str == ']' || *str == '}')
			return (0);
		++str;	
	}
	if (index == 0)
		return (1);
	return (0);
}

int		main(int argc, char *argv[])
{
	int		i;

	if (argc >= 2)
	{
		i = 1;
		while (i < argc)
		{
			if (brackets(argv[i]))
				write(1, "OK\n", 3);
			else
				write(1, "Error\n", 6);
			i++;
		}
	}
	else
		write(1, "\n", 1);
	return (0);
}
