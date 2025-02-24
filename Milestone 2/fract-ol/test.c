/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdalloli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:10:30 by mdalloli          #+#    #+#             */
/*   Updated: 2025/02/12 11:10:32 by mdalloli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// fractol.c
#ifndef FRACTOL_H
# define FRACTOL_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "ft_printf/ft_printf.h"
# include "mlx/mlx.h"

# define WIDTH 800
# define HEIGHT 800
# define MAX_ITER 100
# define COLOR_1 0xFF4500
# define COLOR_2 0xFF00FF
# define COLOR_3 0x0000FF 

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	double	zoom;
	double	move_x;
	double	move_y;
	int		max_iter;
	double	julia_cx;
	double	julia_cy;
	char	*fractal;
	int		needs_redraw;
}	t_data;

void	start_fractol(char *fractal);
void	draw_mandelbrot(t_data *data);
void	draw_julia(t_data *data);
void	put_pixel(t_data *data, int x, int y, int color);
void	cleanup(t_data *data);
int		get_color(int iter);
int		handle_keys(int key, t_data *data);
int		handle_mouse(int button, int x, int y, t_data *data);
int		render_frame(t_data *data);
int		ft_strcmp(char *s1, char *s2);

#endif

// draw.c
void	put_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
		*(unsigned int *)dst = color;
	}
}

int	get_color(int iter)
{
	if (iter < 50)
		return (COLOR_1);
	else if (iter < 100)
		return (COLOR_2);
	else
		return (COLOR_3);
}

// events.c
int	handle_keys(int key, t_data *data)
{
	if (key == 65307)
		cleanup(data);
	return (0);
}

int	handle_mouse(int button, int x, int y, t_data *data)
{
	double	mouse_x;
	double	mouse_y;
	double	zoom_factor;

	if (!data || !data->fractal)
		return (0);
	mouse_x = (x - WIDTH / 2.0) * 4.0 / WIDTH * data->zoom + data->move_x;
	mouse_y = (y - HEIGHT / 2.0) * 4.0 / HEIGHT * data->zoom + data->move_y;
	if (button == 4)
		zoom_factor = 1.1;
	else if (button == 5)
		zoom_factor = 1 / 1.1;
	else
		return (0);
	data->zoom *= zoom_factor;
	data->move_x = mouse_x - (x - WIDTH / 2.0) * 4.0 / WIDTH * data->zoom;
	data->move_y = mouse_y - (y - HEIGHT / 2.0) * 4.0 / HEIGHT * data->zoom;
	data->needs_redraw = 1;
	return (0);
}

// utils.c
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

// julia.c
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

// mandelbrot.c
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

// main.c 
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
