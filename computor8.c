/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computor8.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plisieck <plisieck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/09 23:08:36 by plisieck          #+#    #+#             */
/*   Updated: 2015/06/09 23:10:43 by plisieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"

static void		draw_graph(void *mlx, void *win)
{
	int			i;

	i = -1;
	while (++i < 1361)
		mlx_pixel_put(mlx, win, i, 501, 0x00BBBBBB);
	i = -1;
	while (++i < 1001)
		mlx_pixel_put(mlx, win, 681, i, 0x00BBBBBB);
	i = -1;
	while (++i < 8)
	{
		mlx_pixel_put(mlx, win, 1361 - i, 501 - i, 0x00BBBBBB);
		mlx_pixel_put(mlx, win, 1360 - i, 501 + i, 0x00BBBBBB);
		mlx_pixel_put(mlx, win, 681 - i, 0 + i, 0x00BBBBBB);
		mlx_pixel_put(mlx, win, 681 + i, 0 + i, 0x00BBBBBB);
	}
	mlx_string_put(mlx, win, 685, 505, 0x00FFFFFFF, "0\n");
	mlx_string_put(mlx, win, 685, 4, 0x00FFFFFF, "y");
	mlx_string_put(mlx, win, 1340, 505, 0x00FFFFFF, "x");
	mlx_string_put(mlx, win, 20, 20, 0x000055FF, "f(x)");
	mlx_string_put(mlx, win, 20, 40, 0x00FF0000, "f'(x)");
}

static void		draw_tirets(void *mlx, void *win)
{
	int			i;

	i = -1;
	while (++i < 30)
	{
		mlx_pixel_put(mlx, win, i * 1360 / 30, 504, 0x00BBBBBB);
		mlx_pixel_put(mlx, win, i * 1360 / 30, 503, 0x00BBBBBB);
		mlx_pixel_put(mlx, win, i * 1360 / 30, 502, 0x00BBBBBB);
		mlx_pixel_put(mlx, win, i * 1360 / 30, 500, 0x00BBBBBB);
		mlx_pixel_put(mlx, win, i * 1360 / 30, 499, 0x00BBBBBB);
		mlx_pixel_put(mlx, win, i * 1360 / 30, 498, 0x00BBBBBB);
	}
	i = -1;
	while (++i < 22)
	{
		mlx_pixel_put(mlx, win, 684, i * 1000 / 22 + 1, 0x00BBBBBB);
		mlx_pixel_put(mlx, win, 683, i * 1000 / 22 + 1, 0x00BBBBBB);
		mlx_pixel_put(mlx, win, 682, i * 1000 / 22 + 1, 0x00BBBBBB);
		mlx_pixel_put(mlx, win, 680, i * 1000 / 22 + 1, 0x00BBBBBB);
		mlx_pixel_put(mlx, win, 679, i * 1000 / 22 + 1, 0x00BBBBBB);
		mlx_pixel_put(mlx, win, 678, i * 1000 / 22 + 1, 0x00BBBBBB);
	}
}

static void		draw_function(float *tab, void *mlx, void *win)
{
	double		i;
	double		x;
	double		x2;
	double		y;
	double		y2;

	i = -1;
	while (++i < 1361)
	{
		x = 30 * i / 1360 - 15;
		x2 = 30 * i / 1360 - 15;
		y2 = (tab[1] + (2 * tab[2] * x2));
		y2 = 1000 - (y2 + 11) * 1000 / 22;
		y = (tab[0]) + (x * tab[1]) +
			(x * x * tab[2]);
		y = 1000 - (y + 11) * 1000 / 22;
		mlx_pixel_put(mlx, win, i, y, 0x000055FF);
		mlx_pixel_put(mlx, win, i, y2, 0x00FF0000);
	}
}

static int		gere_key(int keycode, void *mlx)
{
	mlx = (void*)mlx;
	if (keycode == 53)
		exit (1);
	return (1);
}

void			do_mlx(float *tab)
{
	int			i;
	void		*mlx;
	void		*win;

	i = -1;
	mlx = mlx_init();
	win = mlx_new_window(mlx, 1361, 1001, "ComputorV1");
	draw_graph(mlx, win);
	draw_tirets(mlx, win);
	draw_function(tab, mlx, win);
	mlx_key_hook(win, gere_key, mlx);
	mlx_loop(mlx);
}
