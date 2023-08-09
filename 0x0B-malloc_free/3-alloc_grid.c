#include "main.h"
#include <stdlib.h>
/**
 * alloc_grid - nested loop to make grid
 * @width: width input
 * @height: height input
 * Return: pointer to 2 dimensional array
 */
int **alloc_grid(int width, int height)
{
	int **ijo;
	int x, y;

	if (width <= 0 || height <= 0)
		return (NULL);

	ijo = malloc(sizeof(int *) * height);

	if (ijo == NULL)
		return (NULL);

	for (x = 0; x < height; x++)
	{
		ijo[x] = malloc(sizeof(int) * width);

		if (ijo[x] == NULL)
		{
			for (; x >= 0; x--)
				free(ijo[x]);

			free(ijo);
			return (NULL);
		}
	}

	for (x = 0; x < height; x++)
	{
		for (y = 0; y < width; y++)
			ijo[x][y] = 0;
	}

	return (ijo);
}
