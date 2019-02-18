/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   check_s.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: thperchi <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/11 12:47:47 by thperchi     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/18 14:47:28 by jominodi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

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
			if (s[x + 1] == '#')
				y++;
			if (s[x - 1] == '#')
				y++;
			if (s[x - 5] == '#')
				y++;
			if (s[x + 5] == '#')
				y++;
			z++;
		}
		if (s[x] != '.' && s[x] != '#' && s[x] != '\n' && s[x] != '\0')
			return (0);
		if ((x == 4 || x == 9 || x == 14) && s[x] != '\n')
			return (0);
		x++;
	}
	if ((y == 6 || y == 8) && z == 4 && x == 20)
		return (1);
	return (0);
}

int				full_check(t_fillit *list)
{
	int		x;

	x = 0;
	while (list)
	{
		if (!check_s(list->s))
			return (0);
		x++;
		list = list->next;
	}
	return (1);
}
