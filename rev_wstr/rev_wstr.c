#include "unistd.h"

int		recursive(char *ptr)
{
	char	*start;
	int		ret;

	while (*ptr == ' ' || *ptr == '\t')
		ptr++;
	start = ptr;
	while (*ptr && *ptr != ' ' && *ptr != '\t')
		ptr++;
	ret = 0;
	if (start < ptr)
	{
		ret = recursive(ptr);
		if (ret > 0)
			write(1, " ", 1);
		write(1, start, ptr - start);
		ret++;
	}
	return (ret);
}

int		main(int argc, char *argv[])
{
	if (argc == 2)
		recursive(argv[1]);
	write(1, "\n", 1);
	return (0);
}
