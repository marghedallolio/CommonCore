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

static void	init_data(t_data *data)
{
	data->zoom = 1.0;
	data->move_x = 0.0;
	data->move_y = 0.0;
	data->max_iter = MAX_ITER;
	data->julia_cx = -0.7;
	data->julia_cy = 0.27015;
}

static void	init_window_and_image(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
	{
		ft_printf("Errore inizializzazione MiniLibX\n");
		exit(1);
	}
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "Fract'ol");
	if (!data->win)
	{
		ft_printf("Errore creazione finestra\n");
		exit(1);
	}
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->img)
	{
		ft_printf("Errore creazione immagine\n");
		exit(1);
	}
	data->addr = mlx_get_data_addr(data->img, &data->bpp,
			&data->line_len, &data->endian);
	if (!data->addr)
	{
		ft_printf("Errore ottenimento data address\n");
		exit(1);
	}
}

static void	init_fractal(t_data *data, char *fractal)
{
	data->fractal = fractal;
	init_data(data);
	if (!ft_strcmp(fractal, "mandelbrot"))
		draw_mandelbrot(data);
	else if (!ft_strcmp(fractal, "julia"))
		draw_julia(data);
	else
	{
		ft_printf("Usa: ./fractol mandelbrot | julia\n");
		exit(1);
	}
}

void	start_fractol(char *fractal)
{
	t_data	data;

	init_window_and_image(&data);
	init_fractal(&data, fractal);
	mlx_loop_hook(data.mlx, render_frame, &data);
	mlx_key_hook(data.win, handle_keys, &data);
	mlx_mouse_hook(data.win, handle_mouse, &data);
	mlx_hook(data.win, 17, 0, (int (*)(void *))exit, NULL);
	mlx_loop(data.mlx);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_printf("Usa: ./fractol mandelbrot | julia\n");
		return (1);
	}
	start_fractol(argv[1]);
	return (0);
}
