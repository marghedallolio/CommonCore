/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdalloli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 10:52:42 by mdalloli          #+#    #+#             */
/*   Updated: 2025/02/12 10:52:44 by mdalloli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	render_frame(t_data *data)
{
	if (data->needs_redraw)
	{
		if (!ft_strcmp(data->fractal, "mandelbrot"))
			draw_mandelbrot(data);
		else if (!ft_strcmp(data->fractal, "julia"))
			draw_julia(data);
		mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
		data->needs_redraw = 0;
	}
	return (0);
}

void	cleanup(t_data *data)
{
	if (data->img)
		mlx_destroy_image(data->mlx, data->img);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
		free(data->mlx);
	exit(0);
}
