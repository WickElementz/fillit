/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   check_s.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: thperchi <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/11 12:47:47 by thperchi     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/27 18:06:21 by jominodi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

t_fillit		*ft_index(t_fillit *list, int i, int y, int x)
{
	int			j;
	int			check;
	int			ref_y;
	int			ref_x;
	t_fillit	*tmp;

	tmp = list;
	while (list)
	{
		check = 1;
		j = 0;
		x = 0;
		y = 0;
		i = 0;
		while (list->s[i])
		{
			if (list->s[i] == '#')
			{
				if (check == 1)
				{
					ref_y = y;
					ref_x = x;
					check = 0;
				}
				else
				{
					list->index[j] = y - ref_y;
					j++;
					list->index[j] = x - ref_x;
					j++;
				}
			}
			i++;
			x++;
			if (list->s[i] == '\n')
			{
				x = 0;
				i++;
				y++;
			}
		}
		list = list->next;
	}
	list = tmp;
	free(tmp);
	return (list);
}

static int		valid_tetri(int y, char *s, int x)
{
	if (s[x + 1] == '#')
		y++;
	if (s[x - 1] == '#')
		y++;
	if (s[x - 5] == '#')
		y++;
	if (s[x + 5] == '#')
		y++;
	return (y);
}

static int		check_s(char *s)
{
	int x;
	int y;
	int z;

	x = 0;
	y = 0;
	z = 0;
	while (s[x])
	{
		if (s[x] == '#')
		{
			y = valid_tetri(y, s, x);
			z++;
		}
		if (s[x] != '.' && s[x] != '#' && s[x] != '\n' && s[x] != '\0')
			error();
		if ((x == 4 || x == 9 || x == 14) && s[x] != '\n')
			error();
		x++;
	}
	if ((y == 6 || y == 8) && z == 4 && x == 20)
		return (1);
	return (0);
}

int				full_check(t_fillit *list)
{
	int			x;
	char		**map;
	t_fillit	*tmp;
	char		c;
	int			size;

	x = 0;
	tmp = list;
	c = 'A';
	while (list)
	{
		if (!check_s(list->s))
			return (0);
		x++;
		list = list->next;
	}
	map = ft_map(x, map, &size);
	list = tmp;
	list = ft_index(list, 0, 0, 0);
	while (ft_solver(list, map, c, size) == 0)
	{
		free(map);
		size++;
		map = ft_map_upsize(size);
	}
	return (1);
}
