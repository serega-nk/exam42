#include <stdlib.h>

int		ft_abs(int value)
{
	return (value < 0 ? -value : value);
}

char	*ft_itoa_base(int value, int base)
{
	char	*hex;
	int		sign;
	int		size;
	int 	temp;
	char	*res;

	if (base < 2 || base > 16)
		return (NULL);
	hex = "0123456789ABCDEF";
	sign = (base == 10 && value < 0);
	size = sign + 2;
	temp = value;
	while (temp /= base)
		size++;
	res = (char *)malloc(size * sizeof(char));
	if (res)
	{
		res[--size] = '\0';
		res[--size] = hex[ft_abs(value % base)];
		while (value /= base)
			res[--size] = hex[ft_abs(value % base)];
		if (sign)
			res[--size] = '-';
	}
	return (res);
}
