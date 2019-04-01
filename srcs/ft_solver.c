/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_solver.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jominodi <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/01 10:26:26 by jominodi     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/01 10:26:31 by jominodi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fillit.h"

char	**copy_map(char **map, int size)
{
	char	**c_map;
	int		i;

	i = 0;
	c_map = (char **)malloc(sizeof(char *) * (size + 1));
	while (i < size)
	{
		c_map[i] = ft_strdup(map[i]);
		i++;
	}
	c_map[i] = NULL;
	return (c_map);
}

void	display_map(char **map)
{
	int i;

	i = 0;
	while (map[i])
		ft_putendl(map[i++]);
	ft_putchar('\n');
}

void	ft_place_piece(int *tab, char **map, int i, int j, char c)
{
	int three;
	int x;
	int y;

	x = 1;
	y = 0;
	three = 0;
	map[i][j] = c;
	while (three++ < 3)
	{
		map[i + tab[y]][j + tab[x]] = c;
		y += 2;
		x += 2;
	}
}

int		ft_check_position(int *tab, char **map, int i, int j, int size)
{
	int x;
	int y;
	int three;
	int	tmp_i;
	int	tmp_j;

	x = 1;
	y = 0;
	three = 0;
	while (three++ < 3)
	{
		tmp_i = i + tab[y];
		tmp_j = j + tab[x];
		if (tmp_i < 0 || tmp_i >= size || tmp_j < 0 || tmp_j >= size)
			return (0);
		if (map[tmp_i][tmp_j] != '.')
			return (0);
		y += 2;
		x += 2;
	}
	return (1);
}

int		ft_solver(t_fillit *list, char **map, char c, int size)
{
	int		i;
	int		j;
	char	**c_map;

	i = 0;
	if (!list)
	{
		display_map(map);
		return (1);
	}
	while (map[i])
	{
		j = 0;
		while (map[i][j] && list)
		{
			if (map[i][j] == '.')
			{
				if (ft_check_position(list->index, map, i, j, size))
				{
					c_map = copy_map(map, size);
					ft_place_piece(list->index, c_map, i, j, c);
					if (ft_solver(list->next, c_map, c + 1, size))
						return (1);
				}
			}
			j++;
		}
		i++;
	}
	return (0);
}
