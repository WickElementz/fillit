/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fillit.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jominodi <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/02 12:19:27 by jominodi     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/08 11:09:41 by jominodi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fillit.h"

void		error(void)
{
	ft_putstr("error");
	exit(1);
}

t_fillit	*stock(int fd, t_fillit *list, int y, int z)
{
	char		c;
	int			a;
	t_fillit	*tmp;

	tmp = list;
	y = 0;
	list->s = ft_strnew(20);
	while ((a = read(fd, list->s, 20)))
	{
		if (a != 20)
			error();
		z = read(fd, &c, 1);
		if (c != '\n' && c != '\0')
			error();
		if (z)
		{
			list->next = malloc(sizeof(t_fillit));
			list = list->next;
			list->s = ft_strnew(20);
		}
	}
	if (z != 0)
		error();
	list->next = NULL;
	return (tmp);
}

int			main(int ac, char **av)
{
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
	list = stock(fd, list, 0, 0);
	if (full_check(list) == 0)
	{
		free_list(list);
		error();
	}
	free_list(list);
	return (0);
}
