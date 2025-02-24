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

double	get_cx(int x, t_data *data)
{
	return ((x - WIDTH / 2.0) * 4.0 / WIDTH * data->zoom + data->move_x);
}

double	get_cy(int y, t_data *data)
{
	return ((y - HEIGHT / 2.0) * 4.0 / HEIGHT * data->zoom + data->move_y);
}

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
	int		iter;
	int		color;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			iter = mandelbrot_iter(get_cx(x, data), get_cy(y, data));
			color = get_color(iter);
			put_pixel(data, x, y, color);
			x++;
		}
		y++;
	}
}
