/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdfread.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaidoo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/01 08:39:32 by mnaidoo           #+#    #+#             */
/*   Updated: 2017/09/11 11:00:19 by mnaidoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		value(int x, int y, int z)
{
	if (x == 0)
		return (y);
	else if (z == y)
		return (z);
	else
		return (-1);
}

int		line(char *str, int x, int y)
{
	int i;
	int j;
	int z;

	i = 0;
	j = 0;
	z = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
		{
			if (str[i] != ' ')
				return (-1);
			j = 0;
		}
		else
		{
			if (j == 0)
				z++;
			j++;
		}
		i++;
	}
	return (value(x, z, y));
}

int		split(t_fdf *readmap, char *st)
{
	int		i;
	char	**str;

	i = 0;
	str = ft_strsplit(st, ' ');
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	if (readmap->lines == 0)
		readmap->character = i;
	else
	{
		if (i != readmap->character)
			return (-1);
	}
	free(st);
	free(str);
	readmap->lines++;
	return (0);
}

int		memalloc(t_fdf *read)
{
	char	*st;
	int		ret;

	st = NULL;
	read->lines = 0;
	read->character = 0;
	while ((ret = get_next_line(read->fd, &st)) > 0)
	{
		if (split(read, st) == -1)
			return (-1);
	}
	read->map = ft_memalloc(sizeof(int*) * read->lines);
	close(read->fd);
	read->fd = open(read->head, O_RDONLY);
	return (0);
}

int		readline(t_fdf *read)
{
	char	*str;
	char	**st;
	int		xyst[3];

	xyst[1] = 0;
	if (memalloc(read) == -1)
		return (-1);
	while ((xyst[2] = get_next_line(read->fd, &str)) > 0)
	{
		xyst[0] = 0;
		st = ft_strsplit(str, ' ');
		read->map[xyst[1]] = ft_memalloc(sizeof(int) * read->character);
		while (st[xyst[0]] != NULL)
		{
			read->map[xyst[1]][xyst[0]] = ft_atoi(st[xyst[0]]);
			free(st[xyst[0]]);
			xyst[0]++;
		}
		free(st);
		xyst[1]++;
	}
	return ((xyst[2] == -1) ? -1 : 0);
}
