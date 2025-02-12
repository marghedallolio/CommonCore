/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdalloli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:13:47 by mdalloli          #+#    #+#             */
/*   Updated: 2025/02/12 11:13:48 by mdalloli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


static int	mandelbrot_iter(double cx, double cy)
{
	double	zx;
	double	zy;
	double	tmp;
	int		iter;

	zx = 0;
	zy = 0;
	iter = 0;
	while (zx * zx + zy * zy < 4 && iter < MAX_ITER)
	{
		tmp = zx * zx - zy * zy + cx;
		zy = 2.0 * zx * zy + cy;
		zx = tmp;
		iter++;
	}
	return (iter);
}

void	draw_mandelbrot(t_data *data)
{
	int		x;
	int		y;
	double	cx;
	double	cy;
	int		iter;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			cx = (x - WIDTH / 2.0) * 4.0 / WIDTH * data->zoom + data->move_x;
			cy = (y - HEIGHT / 2.0) * 4.0 / HEIGHT * data->zoom + data->move_y;
			iter = mandelbrot_iter(cx, cy);
			put_pixel(data, x, y, iter * 0x00FF00);
		}
	}
}
