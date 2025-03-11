#include "fractol.h"

void	init_data(t_data *data)
{
	data->zoom = 1.0;
	data->move_x = 0.0;
	data->move_y = 0.0;
	data->max_iter = MAX_ITER;
	data->julia_cx = -0.7;
	data->julia_cy = 0.27015;
	data->needs_redraw = 1;
}

void	init_window_and_image(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		exit_with_error("Errore inizializzazione MiniLibX");
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "Fract'ol");
	if (!data->win)
	{
		ft_printf("Errore creazione finestra\n");
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		exit(1);
	}
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->img)
	{
		ft_printf("Errore creazione immagine\n");
		clean_exit(data);
	}
	data->addr = mlx_get_data_addr(data->img, &data->bpp,
			&data->line_len, &data->endian);
	if (!data->addr)
	{
		ft_printf("Errore ottenimento data address\n");
		mlx_destroy_image(data->mlx, data->img);
		clean_exit(data);
	}
}

void	init_fractal(t_data *data, char *fractal)
{
	if (!fractal)
	{
		ft_printf("Fractal non puo' essere NULL\n");
		clean_exit(data);
	}
	data->fractal = fractal;
	init_data(data);
	if (!ft_strcmp(fractal, "mandelbrot"))
		draw_mandelbrot(data);
	else if (!ft_strcmp(fractal, "julia"))
		draw_julia(data);
	else
	{
		ft_printf("Usa: ./fractol mandelbrot | julia\n");
		clean_exit(data);
	}
}

void	start_fractol(char *fractal)
{
	t_data	data;

	ft_bzero(&data, sizeof(t_data));
	init_fractal(&data, fractal);
	init_window_and_image(&data);
	data.needs_redraw = 1;
	mlx_loop_hook(data.mlx, render_frame, &data);
	mlx_key_hook(data.win, handle_keys, &data);
	mlx_mouse_hook(data.win, handle_mouse, &data);
	mlx_hook(data.win, 17, 0, (int (*)(void *))clean_exit, &data);
	mlx_loop(data.mlx);
}
