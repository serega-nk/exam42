#include <stdio.h>

char		*ft_itoa_base(int value, int base);

int			main(void)
{
	printf("|%s|\n", ft_itoa_base(0, -10));

	printf("|%s|\n", ft_itoa_base(100, 16));
	printf("|%s|\n", ft_itoa_base(100, 10));
	printf("|%s|\n", ft_itoa_base(-100, 16));
	printf("|%s|\n", ft_itoa_base(0, 10));
	printf("|%s|\n", ft_itoa_base(0, 12));

	printf("|%s|\n", ft_itoa_base(-2147483648, 2));
	printf("|%s|\n", ft_itoa_base(2147483647, 2));
	printf("|%s|\n", ft_itoa_base(-2147483648, 8));
	printf("|%s|\n", ft_itoa_base(2147483647, 8));
	printf("|%s|\n", ft_itoa_base(-2147483648, 16));
	printf("|%s|\n", ft_itoa_base(2147483647, 16));

	return (0);
}
