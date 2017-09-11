/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdfmain.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaidoo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/01 15:42:36 by mnaidoo           #+#    #+#             */
/*   Updated: 2017/09/11 10:21:28 by mnaidoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf(t_fdf *read)
{
	if (readline(read) == -1)
	{
		ft_putendl("ERROR!");
		return ;
	}
	mlx(read);
}

int		main(int ac, char **av)
{
	t_fdf mine;

	if (ac == 2)
	{
		mine.head = av[1];
		mine.fd = open(mine.head, O_RDONLY);
		fdf(&mine);
	}
	else
		ft_putendl("correct ./fdf file please!!!(passive aggresive voice)");
	return (0);
}
