#include <stdio.h>

char	*ft_itoa_base(int value, int base);

void	test(int value)
{
	printf("1 - 16 |%x|\n", value);
	printf("2 - 16 |%s|\n", ft_itoa_base(value, 16));
	printf("1 - 10 |%d|\n", value);
	printf("2 - 10 |%s|\n", ft_itoa_base(value, 10));
	printf("1 -  8 |%o|\n", value);
	printf("2 -  8 |%s|\n", ft_itoa_base(value, 8));
	printf("2 -  2 |%s|\n", ft_itoa_base(value, 2));
	printf("============\n");
}

int		main(void)
{
	test(-1);
	test(1);
	test(0);
	test(-2147483648);
	test(2147483647);
	test(888888);
	test(0xCCCCCFF);

	return (0);
}
