/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdalloli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 10:52:02 by mdalloli          #+#    #+#             */
/*   Updated: 2025/02/12 10:52:03 by mdalloli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	exit_with_error(char *msg)
{
	ft_printf("%s\n", msg);
	exit(1);
}

int	clean_exit(t_data *data)
{
	cleanup(data);
	exit(0);
	return (0);
}

void	start_fractol(char *fractal, t_data *data)
{
	if (!fractal)
		exit_with_error("Errore: fractal non puo' essere NULL \n");
	data->fractal = fractal;
	init_data(data);
	init_window_and_image(data);
	if (!ft_strcmp(fractal, "mandelbrot"))
		draw_mandelbrot(data);
	else if (!ft_strcmp(fractal, "julia"))
		draw_julia(data);
	data->needs_redraw = 1;
	mlx_loop_hook(data->mlx, render_frame, data);
	mlx_key_hook(data->win, handle_keys, data);
	mlx_mouse_hook(data->win, handle_mouse, data);
	mlx_hook(data->win, 17, 0, (int (*)(void *))clean_exit, data);
	mlx_loop(data->mlx);
}

int	main(int argc, char **argv)
{
	t_data	data;
	char	*ptr1;
	char	*ptr2;

	if (argc < 2 || argc > 4)
		exit_with_error("Usa: ./fractol mandelbrot | julia [cx cy]\n");
	ft_bzero(&data, sizeof(t_data));
	if (ft_strcmp(argv[1], "julia") == 0)
	{
		data.julia_cx = -0.7;
		data.julia_cy = 0.27015;
		if (argc == 4)
		{
			data.julia_cx = ft_strtod(argv[2], &ptr1);
			data.julia_cy = ft_strtod(argv[3], &ptr2);
		}
	}
	else if (ft_strcmp(argv[1], "mandelbrot") != 0)
		exit_with_error("Errore: Usa ./fractol mandelbrot | julia [cx cy]\n");
	start_fractol(argv[1], &data);
	return (0);
}
