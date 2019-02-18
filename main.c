/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: thperchi <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/11 12:44:08 by thperchi     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/18 14:53:30 by jominodi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

t_fillit	*stock(int fd, t_fillit *list)
{
	int y;
	int z;
	char c;
	t_fillit *tmp;

	y = 0;
	z = read(fd, &c, 1);
	tmp = list;
	while (z)
	{
		list->s = malloc(sizeof(char *) * 20);
		while (y != 20)
		{
			list->s[y] = c;
			y++;
			z = read(fd, &c, 1);
		}
		list->s[y] = '\0';
		if (c == '\n')
			z = read(fd, &c, 1);
		y = 0;
		printf("%s\n", list->s);
		if (c == '\0')
			break;
		
		if (z != '\0')
		{
			list->next = malloc(sizeof(t_fillit));
			list = list->next;
		}
	}
	list->next = NULL;
	list = tmp;
	return (list);
}

int				main(int ac, char **av)
{
	char		*s;
	int			fd;
	t_fillit	*list;

	if (ac != 2)
	{
		ft_putstr("usage: fillit imput_file\n");
		return (0);
	}
	fd = open(av[1], O_RDONLY);
	list = (t_fillit *)malloc(sizeof(t_fillit));
	list = stock(fd, list);
	if (!full_check(list))
	{
		printf(red"Sombre Merde\n"reset);
		return (0);
	}
	printf(green"GG FDP"reset);
	return (0);
}
