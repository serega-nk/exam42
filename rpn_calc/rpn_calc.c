#include "unistd.h"
#include "stdio.h"

int		make_opt(char **addr, int *a, int *b)
{
	if (**addr == '+')
	{
		*a += *b;
		(*addr)++;
		return (1);
	}
	else if (**addr == '-')
	{
		*a -= *b;
		(*addr)++;
		return (1);
	}
	else if (**addr == '*')
	{
		*a *= *b;
		(*addr)++;
		return (1);
	}
	else if (**addr == '/')
	{
		*a /= *b;
		(*addr)++;
		return (1);
	}
	else if (**addr == '%')
	{
		*a %= *b;
		(*addr)++;
		return (1);
	}	
	return (0);
}

int		parse_int(char **addr, int *avalue)
{
	char	*ptr;
	int		value;
	
	ptr = *addr;
	value = 0;
	while (*ptr >= '0' && *ptr <= '9')
	{
		value = value * 10 + (*ptr - '0');
		ptr++;
	}
	if (ptr > *addr)
	{
		*addr = ptr;
		*avalue = value;
		return (1);
	}
	return (0);
}

int		rpn_calc(char *str, int *avalue)
{
	int		stack[1000];
	int		count;

	count = 0;
	while (*str)
	{
		while (*str == ' ')
			str++;
		if (count >= 2 && make_opt(&str, &stack[count - 2], &stack[count - 1]))
			count--;
		else if (parse_int(&str, &stack[count]))
			count++;
		else if (*str)
			return (0);
		if (*str && *str != ' ')
			return (0);
	}
	if (count == 1)
	{
		*avalue = stack[0];
		return (1);
	}
	return (0);
}

int		main(int argc, char *argv[])
{
	int value;

	value = 0;
	if (argc == 2 && rpn_calc(argv[1], &value))
		printf("%d\n", value);
	else
		printf("Error\n");
	return (0);
}
