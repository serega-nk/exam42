#include <unistd.h>

int		check_mate(char *map[], int size, int x, int y)
{
	return (x >= 0 && y >= 0 && x < size && y < size && map[x][y] == 'K');
}

int		walk_pawn(char *map[], int size, int x, int y)
{
	if (map[x][y] == 'P')
	{
		if (check_mate(map, size, x - 1, y - 1) ||
			check_mate(map, size, x + 1, y - 1))
			return (1);
	}
	return (0);
}

int		walk_bishop(char *map[], int size, int x, int y)
{
	int		i;

	if (map[x][y] == 'B')
	{
		i = 1;
		while (i < size)
		{
			if (check_mate(map, size, x - i, y - i) ||
				check_mate(map, size, x + i, y - i) || 
				check_mate(map, size, x + i, y + i) ||
				check_mate(map, size, x - i, y + i)
				)
			return (1);
			i++;
		}
	}
	return (0);
}

int		walk_rook(char *map[], int size, int x, int y)
{
	int		i;

	if (map[x][y] == 'R')
	{
		i = 1;
		while (i < size)
		{
			if (check_mate(map, size, x + i, y) ||
				check_mate(map, size, x - i, y) || 
				check_mate(map, size, x, y + i) ||
				check_mate(map, size, x, y - i)
				)
			return (1);
			i++;
		}
	}
	return (0);
}

int		walk_queen(char *map[], int size, int x, int y)
{
	int		i;

	if (map[x][y] == 'Q')
	{
		i = 1;
		while (i < size)
		{
			if (check_mate(map, size, x - i, y - i) ||
				check_mate(map, size, x + i, y - i) || 
				check_mate(map, size, x + i, y + i) ||
				check_mate(map, size, x - i, y + i) ||
				check_mate(map, size, x + i, y) ||
				check_mate(map, size, x - i, y) || 
				check_mate(map, size, x, y + i) ||
				check_mate(map, size, x, y - i)
				)
			return (1);
			i++;
		}
	}
	return (0);
}

int		checkmate(char *map[], int size)
{
	int		x;
	int		y;

	x = 0;
	while (x < size)
	{
		y = 0;
		while (y < size)
		{
			if (walk_pawn(map, size, x, y) ||
				walk_bishop(map, size, x, y) || 
				walk_rook(map, size, x, y) || 
				walk_queen(map, size, x, y))
				return (1);
			y++;
		}
		x++;
	}
	return (0);
}

int		main(int argc, char *argv[])
{
	if (argc > 1)
	{
		if (checkmate(argv + 1, argc - 1))
			write(1, "Success", 7);
		else
			write(1, "Fail", 4);
	}
	write(1, "\n", 1);
	return (0);
}
