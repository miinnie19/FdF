/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaidoo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/01 15:50:44 by mnaidoo           #+#    #+#             */
/*   Updated: 2017/09/11 10:22:46 by mnaidoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include "libft.h"
# define WIDTH 1000
# define HEIGHT 1000

typedef struct		s_fdf
{
	int				fd;
	char			*head;
	void			*mlx;
	void			*win;
	int				**map;
	int				lines;
	int				check;
	int				character;
	int				z;
	int				dx;
	int				dy;
	int				sx;
	int				sy;
	int				color;
}					t_fdf;

void				checks(t_fdf *line);
void				lines(t_fdf *line, int x, int y);
void				check_env(t_fdf *draw);
void				draw(t_fdf *draw, int *stxy, int x, int y);
void				mlx(t_fdf *key);
int					keyboard(int keycode, t_fdf *key);
void				move(int keycode, t_fdf *key);
int					cross(void);
void				zoom(int keycode, t_fdf *key);
void				drawline(t_fdf *draw);
int					readline(t_fdf *read);
int					memalloc(t_fdf *read);
int					split(t_fdf *readmap, char *st);
int					line(char *str, int x, int y);
int					value(int x, int y, int z);
void				fdf(t_fdf *read);

#endif
