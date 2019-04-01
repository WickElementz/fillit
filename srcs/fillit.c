/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fillit.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jominodi <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/01 10:25:59 by jominodi     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/01 10:35:58 by jominodi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fillit.h"

void		error(void)
{
	ft_putstr("error");
	exit(1);
}

t_fillit	*stock(int fd, t_fillit *list)
{
	int			y;
	int			z;
	char		c;
	t_fillit	*tmp;

	y = 0;
	z = read(fd, &c, 1);
	tmp = list;
	if (c != '.' && c != '#')
		error();
	while (z)
	{
		list->s = ft_strnew(20);
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
		if (c == '\0')
			break ;
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

int			main(int ac, char **av)
{
	//char		*s;
	int			fd;
	t_fillit	*list;

	if (ac != 2)
	{
		ft_putstr("usage: fillit input_file\n");
		return (0);
	}
	if (!(fd = open(av[1], O_RDONLY)))
		error();
	list = (t_fillit *)malloc(sizeof(t_fillit));
	list = stock(fd, list);
	if (full_check(list) == 0)
		error();
	return (0);
}