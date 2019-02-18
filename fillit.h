/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fillit.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: thperchi <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/11 19:05:38 by thperchi     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/18 13:45:00 by jominodi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "./libft/libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# define red     "\x1b[31m"
# define green   "\x1b[32m"
# define yellow  "\x1b[33m"
# define blue    "\x1b[34m"
# define magenta "\x1b[35m"
# define cyan    "\x1b[36m"
# define reset   "\x1b[0m"

typedef struct		s_fillit
{
	char			*s;
	struct s_fillit	*next;
}					t_fillit;

int					full_check(t_fillit *list);
t_fillit			*stock(int fd, t_fillit *list);
int					num_char(char *str);

#endif
