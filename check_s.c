/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   check_s.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: thperchi <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/11 12:47:47 by thperchi     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/12 16:20:29 by jominodi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

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
	return (0);;
}

int				full_check(t_fillit *list)
{
	int		x;
	char	**map;
	t_fillit	*tmp;
	char c;

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
	map = ft_map(x, map);
	list = tmp;
	map = ft_solver(list, map, c);
	x = 0;
	/*while (map[x])
	{
		ft_putstr(map[x]);
		printf("\n");
		x++;
	}*/
	return (1);
}
