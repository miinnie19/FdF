/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdfkeys.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaidoo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/01 16:12:24 by mnaidoo           #+#    #+#             */
/*   Updated: 2017/09/11 10:22:04 by mnaidoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		zoom(int keycode, t_fdf *key)
{
	if (keycode == 69 && key->sx * 2 <= 500 && key->sy * 2 <= 500)
	{
		mlx_clear_window(key->mlx, key->win);
		key->sx *= 2;
		key->sy *= 2;
		key->z *= 2;
		drawline(key);
		ft_putnbr(keycode);
		ft_putchar('\n');
	}
	if (keycode == 78 && key->sx * 0.5 >= 1 && key->sy * 0.5 >= 1 &&
			(-key->z * 0.5 >= 1 || key->z * 0.5 >= 1))
	{
		mlx_clear_window(key->mlx, key->win);
		key->sx *= 0.5;
		key->sy *= 0.5;
		key->z *= 0.5;
		drawline(key);
		ft_putnbr(keycode);
		ft_putchar('\n');
	}
}

int			cross(void)
{
	exit(0);
	return (0);
}

void		move(int keycode, t_fdf *key)
{
	if ((keycode >= 123 && keycode <= 126) || keycode == 15)
	{
		mlx_clear_window(key->mlx, key->win);
		if (keycode == 123)
			key->dx -= 5;
		if (keycode == 126)
			key->dy -= 5;
		if (keycode == 124)
			key->dx += 10;
		if (keycode == 125)
			key->dy += 5;
		if (keycode == 15)
			key->check = 0;
		drawline(key);
	}
}

int			keyboard(int keycode, t_fdf *key)
{
	if (keycode == 53)
		cross();
	if (keycode == 67)
	{
		mlx_clear_window(key->mlx, key->win);
		key->z++;
		drawline(key);
	}
	if (keycode == 75)
	{
		mlx_clear_window(key->mlx, key->win);
		key->z--;
		drawline(key);
	}
	if (keycode == 8)
	{
		mlx_clear_window(key->mlx, key->win);
		if (key->check % 12 == 0)
			key->color = 0xFF000000;
		key->color = key->color >> 2;
		drawline(key);
	}
	zoom(keycode, key);
	move(keycode, key);
	return (0);
}

void		mlx(t_fdf *key)
{
	key->check = 0;
	key->mlx = mlx_init();
	key->win = mlx_new_window(key->mlx, WIDTH, HEIGHT, "Fdf");
	drawline(key);
	mlx_key_hook(key->win, keyboard, key);
	mlx_hook(key->win, 17, (1L << 17), cross, key);
	mlx_loop(key->mlx);
}
