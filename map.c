/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jominodi <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/26 11:34:49 by jominodi     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/12 16:01:20 by jominodi    ###    #+. /#+    ###.fr     */
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

char		**ft_map(int	x, char **map)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = sqrt(x);
	printf(magenta"Nombre de Tetriminos: %d\nTaille de la map: %d x %d\n"reset, x, k, k);
	printf("\n");
	map = (char **)malloc(sizeof(char *) * (k + 1));
	while (i < k)
	{
		map[i] = ft_strnew(k);
		while (j < k)
		{
			map[i][j] = '.';
			j++;
		}
		i++;
		j = 0;
	}
	map[i] = NULL;
	return (map);
}
