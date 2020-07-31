#include <stdlib.h>

char	*ft_itoa_base(int value, int base)
{
	int				sign;
	int				size;
	unsigned int	n;
	char			*hex;
	char			*res;

	if (base < 2 || base > 16)
		return (NULL);
	sign = (base == 10 && value < 0);
	size = 2 + sign;
	n = sign ? (unsigned int)-value : (unsigned int)value;
	while (n /= base)
		size++;
	hex = "0123456789ABCDEF";
	res = (char *)malloc(size * sizeof(char));
	if (res)
	{
		n = sign ? (unsigned int)-value : (unsigned int)value;
		res[--size] = '\0';
		res[--size] = hex[n % base];	
		while (n /= base)
			res[--size] = hex[n % base];
		if (sign)
			res[--size] = '-';
	}
	return (res);
}
