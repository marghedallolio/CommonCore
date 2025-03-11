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

static double	get_zx(int x, t_data *data)
{
	return ((x - WIDTH / 2.0) * 4.0 / WIDTH * data->zoom + data->move_x);
}

static double	get_zy(int y, t_data *data)
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
	t_julia	j;

	j.y = 0;
	while (j.y < HEIGHT)
	{
		j.x = 0;
		while (j.x < WIDTH)
		{
			j.zx = get_zx(j.x, data);
			j.zy = get_zy(j.y, data);
			j.iter = julia_iter(j.zx, j.zy, data->julia_cx, data->julia_cy);
			j.color = get_color(j.iter);
			put_pixel(data, j.x, j.y, j.color);
			j.x++;
		}
		j.y++;
	}
}
