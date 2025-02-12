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

void	start_fractol(char *fractal)
{
	t_data data;
	data.mlx = mlx_init(); //inizializza MiniLibX
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "Fract'ol"); //crea una finestra
	init_data(&data);
	if (!ft_strcmp(fractal, "mandelbrot")) //controlla quale frattale disegnare
		draw_mandelbrot(&data);
	else if (!ft_strcmp(fractal, "julia"))
		draw_julia(&data);
	else
	{
		ft_printf("Usa: ./fractol mandelbrot | julia \n");
		exit(1);
	}
	//registra i gestori di eventi
	mlx_key_hook(data.win, handle_keys, &data);
	mlx_mouse_hook(data.win, handle_mouse, &data);
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
