/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdalloli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:14:41 by mdalloli          #+#    #+#             */
/*   Updated: 2025/02/12 11:14:52 by mdalloli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handle_keys(int key)
{
	if (key == 65307)
		exit(0);
	return (0);
}

int	handle_mouse(int button, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (button == 4)
		data->zoom *= 1.1;
	else if (button == 5)
		data->zoom /= 1.1;
	if (!ft_strcmp(data->fractal, "mandelbrot"))
		draw_mandelbrot(data);
	else if (!ft_strcmp(data->fractal, "julia"))
		draw_julia(data);
	draw_mandelbrot(data);
	return (0);
}


