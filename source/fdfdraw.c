/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdfdraw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaidoo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/01 12:05:50 by mnaidoo           #+#    #+#             */
/*   Updated: 2017/09/11 10:58:25 by mnaidoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw(t_fdf *draw, int *stxy, int x, int y)
{
	int	stx[2];
	int	sty[2];
	int	i[2];
	int	x0;
	int	y0;

	x0 = stxy[0];
	y0 = stxy[1];
	stx[0] = abs(x - x0);
	stx[1] = x0 < x ? 1 : -1;
	sty[0] = abs(y - y0);
	sty[1] = y0 < y ? 1 : -1;
	i[0] = (stx[0] > sty[0] ? stx[0] : -sty[0]) / 2;
	while (x0 != x || y0 != y)
	{
		mlx_pixel_put(draw->mlx, draw->win, x0, y0, draw->color);
		i[1] = i[0];
		i[1] > -stx[0] ? i[0] -= sty[0] : 1 == 1;
		i[1] > -stx[0] ? x0 += stx[1] : 1 == 1;
		i[1] < sty[0] ? i[0] += stx[0] : 1 == 1;
		i[1] < sty[0] ? y0 += sty[1] : 1 == 1;
	}
}

void	checks(t_fdf *line)
{
	if (line->check == 0)
	{
		line->z = -5;
		line->dx = WIDTH * 0.4;
		line->dy = 20;
		line->sx = (WIDTH * 0.7) / (line->character - line->sx);
		line->sy = (HEIGHT * 0.4) / (line->lines - line->sy);
		line->color = 0x00FFFFFF;
	}
	line->check++;
}

void	lines(t_fdf *line, int x, int y)
{
	int stxy[2];

	stxy[0] = line->dx + (x - y);
	stxy[1] = line->dy + line->map[y / line->sy][x / line->sx] * line->z
		+ x + y;
	if (x / line->sx < line->character - 1 && y / line->sy < line->lines)
		draw(line, stxy, line->dx + ((x + line->sx) - y),
				line->dy + line->map[y / line->sy][x / line->sx + 1] * line->z +
				(x + line->sx) + y);
	if (y / line->sy < line->lines - 1 && x / line->sx < line->character)
		draw(line, stxy, line->dx + (x - (y + line->sy)),
				line->dy + line->map[y / line->sy + 1][x / line->sx] * line->z +
				x + (y + line->sy));
}

void	drawline(t_fdf *line)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	checks(line);
	while (x / line->sx < line->character || y / line->sy < line->lines - 1)
	{
		if (x / line->sx == line->character)
		{
			x = 0;
			y += line->sy;
		}
		lines(line, x, y);
		x += line->sx;
	}
}
