/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdalloli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:14:03 by mdalloli          #+#    #+#             */
/*   Updated: 2025/02/12 11:14:09 by mdalloli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	get_zx(int x, t_data *data)
{
	return ((x - WIDTH / 2.0) * 4.0 / WIDTH * data->zoom + data->move_x);
}

double	get_zy(int y, t_data *data)
{
	return ((y - HEIGHT / 2.0) * 4.0 / HEIGHT * data->zoom + data->move_y);
}

static int	julia_iter(double zx, double zy, double cx, double cy)
{
	double	tmp;
	int		iter;

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

void	draw_julia(t_data *data)
{
	int		x;
	int		y;
	int		iter;
	int		color;
	double	zx;
	double	zy;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{

			zx = get_zx(x, data);
			zy = get_zy(y, data);
			iter = julia_iter(zx, zy, data->julia_cx, data->julia_cy);
			color = get_color(iter);
			put_pixel(data, x, y, color);
			x++;
		}
		y++;
	}
}
