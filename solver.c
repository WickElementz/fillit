/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   solver.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jominodi <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/26 11:24:57 by jominodi     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/12 16:20:31 by jominodi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"
/*
char	**ft_solver(t_fillit *list, char **map, char c, int x)
{
	int	i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	while (i < 18)
	{
		if (list->s[i] == '#' && map[j][k] == '.')
		{
			map[j][k] = c;
		}
		if (map[j][k] == '\0')
		{
			j++;
			k = 0;
		}
		if (map[j][k] == '\0')
			return (ft_solver(list, map, c, x + 1));
		i++;
		k++;
	}
	if (list->next)
		return (ft_solver(list->next, map, c + 1, x));
	map[j] = NULL;
	return (map);
}
*/
char	**ft_solver(t_fillit *list, char **map, char c)
{
	int	i;
	int	j;
	int	k;
	int	l;

	i = 0;
	j = 0;
	k = 0;
	l = 0;
	while (map[j])
	{
		j++;
		l++;
	}
	printf(green"%d\n\n%d\n\n"reset, j, l);
	j = 0;
	l--;
	while (l >= 0)
	{
		printf("%s\n", map[l]);
		l--;
	}
	while (list->s[i])
	{
		dprintf(1, blue"allo"reset);
		while (list->s[i] == '.' || list->s[i] == '\n')
			i++;
		dprintf(1, green"allo"reset);
		dprintf(1, "%d | %d", j, k);
		if (list->s[i] == '#' && map[j][k] == '.')
		{
			printf(red"allo"reset);
			map[j][k] = c;
			k++;
			i++;
			if (map[j][k] == '\0')
			{
				j++;
				k = 0;
			}
		}
		if (j == l && k == l)
			break;

	}
	map[j] = NULL;
	return (map);
}
