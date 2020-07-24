#include "unistd.h"

void	brainfuck(char *cmd)
{
	char	data[2048];
	char	*ptr;
	int		i;

	i = 0;
	ptr = data;
	while (i < 2048)
		ptr[i++] = '\0';	
	while (*cmd)
	{
		if (*cmd == '>')
			ptr++;
		else if (*cmd == '<')
			ptr--;
		else if (*cmd == '+')
			(*ptr)++;
		else if (*cmd == '-')
			(*ptr)--;
		else if (*cmd == '.')
			write(1, ptr, 1);
		else if (*cmd == '[' && !*ptr)
		{
			i = 1;
			while (i)
			{
				cmd++;
				if (*cmd == '[')
					i++;
				else if (*cmd == ']')
					i--;				
			}
		}
		else if (*cmd == ']' && *ptr)
		{
			i = 1;
			while (i)
			{
				cmd--;
				if (*cmd == ']')
					i++;
				else if (*cmd == '[')
					i--;				
			}
		}
		cmd++;
	}
}

int		main(int argc, char *argv[])
{
	if (argc == 2)
		brainfuck(argv[1]);
	else
		write(1, "\n", 1);
	return (0);
}
