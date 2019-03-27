/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jominodi <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/26 11:34:49 by jominodi     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/25 11:47:15 by jominodi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

static int	sqrt(int x)
{
	int size;

	size = 2;
	x *= 4;
	while (size * size < x)
		size++;
	return (size);
}

char		**ft_map_upsize(int size)
{
	char	**map;
	int		i;
	int		j;

	i = 0;
	map = (char **)malloc(sizeof(char *) * (size + 1));
	while (i < size)
	{
		j = 0;
		map[i] = ft_strnew(size);
		while (j < size)
		{
			map[i][j] = '.';
			j++;
		}
		i++;
	}
	map[i] = NULL;
	return (map);
}

char		**ft_map(int x, char **map, int *size)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	k = sqrt(x);
	*size = k;
	printf(MAGENTA"Nombre de Tetriminos: %d\nTaille de la map: %d x %d\n"RESET, x, k, k);
	printf("\n");
	map = (char **)malloc(sizeof(char *) * (k + 1));
	while (i < k)
	{
		j = 0;
		map[i] = ft_strnew(k);
		while (j < k)
		{
			map[i][j] = '.';
			j++;
		}
		i++;
	}
	map[i] = NULL;
	return (map);
}
