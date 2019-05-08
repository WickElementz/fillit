/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   free.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jominodi <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/07 13:37:27 by jominodi     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/08 15:35:36 by jominodi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fillit.h"

int			clean(char **map)
{
	free_double_char(map);
	return (1);
}

t_fillit	*free_list(t_fillit *list)
{
	if (list->next)
		free_list(list->next);
	if (list)
	{
		free(list->s);
		free(list);
	}
	return (NULL);
}

void		free_double_char(char **map)
{
	int	i;

	i = -1;
	if (!map)
		return ;
	while (map[++i])
		free(map[i]);
	free(map);
}
