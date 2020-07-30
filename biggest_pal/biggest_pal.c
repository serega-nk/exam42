#include <unistd.h>

size_t	ft_strlen(char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

int		is_pal(char *s, size_t len)
{
	size_t	index;

	index = 0;
	while (index < len / 2)
	{
		if (s[index] != s[len - 1 - index])
			return (0);
		index++;
	}
	return (1);
}

void	biggest_pal(char *s)
{
	size_t	save_index;
	size_t	save_size;
	size_t	length;
	size_t	index;
	size_t	size;

	save_index = 0;
	save_size = 0;
	length = ft_strlen(s);
	index = 0;
	while (index < length)
	{
		size = length - index;
		while (size > 0 && size >= save_size)
		{
			if (is_pal(s + index, size))
			{
				save_index = index;
				save_size = size;
				break ;
			}
			size--;
		}
		index++;
	}
	write(1, s + save_index, save_size);
}

int		main(int argc, char *argv[])
{
	if (argc == 2)
		biggest_pal(argv[1]);
	write(1, "\n", 1);
	return (0);
}
