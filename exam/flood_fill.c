#include "flood_fill.h"

void	fill(char **area, t_point size, t_point begin, char c)
{
	area[begin.y][begin.x] = 'F';
	if (begin.y > 0 && area[begin.y - 1][begin.x] == c)
		fill(area, size, (t_point){begin.x, begin.y - 1}, c);
	if (begin.y < size.y - 1 && area[begin.y + 1][begin.x] == c)
		fill(area, size, (t_point){begin.x, begin.y + 1}, c);
	if (begin.x > 0 && area[begin.y][begin.x - 1] == c)
		fill(area, size, (t_point){begin.x - 1, begin.y}, c);
	if (begin.x < size.x - 1 && area[begin.y][begin.x + 1] == c)
		fill(area, size, (t_point){begin.x + 1, begin.y}, c);
}

void	flood_fill(char **area, t_point size, t_point begin)
{
	char	c = area[begin.y][begin.x];
	fill(area, size, begin, c);
}

char** make_area(char** zone, t_point size)
{
	char** new;

	new = malloc(sizeof(char*) * size.y);
	for (int i = 0; i < size.y; ++i)
	{
		new[i] = malloc(size.x + 1);
		for (int j = 0; j < size.x; ++j)
			new[i][j] = zone[i][j];
		new[i][size.x] = '\0';
	}

	return new;
}

int main(void)
{
	t_point size = {8, 5};
	char *zone[] = {
		"11111111",
		"10001001",
		"10010001",
		"10110001",
		"11100001",
	};

	char**  area = make_area(zone, size);
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area[i]);
	printf("\n");

	t_point begin = {7, 4};
	flood_fill(area, size, begin);
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area[i]);
	return (0);
}
