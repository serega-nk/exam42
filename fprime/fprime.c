#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	int		count;
	int		i;
	int		n;

	if (argc == 2)
	{
		count = 0;
		n = atoi(argv[1]);
		if (n == 1)
			printf("1");
		else
		{
			i = 2;
			while (i <= n)
			{
				if (n % i == 0)
				{
					if (count > 0)
						printf("*");	
					printf("%d", i);
					n /= i;
					count++;
				}
				else
				{
					i++;
				}
			}
		}
	}
	printf("\n");
	return (0);
}
