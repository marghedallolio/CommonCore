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

#ifndef FRACTOL_H
# define FRACTOL_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "libft_printf/libft_printf.h"
# include "mlx/mlx.h"

# define WIDTH 800
# define HEIGHT 800
# define MAX_ITER 100
# define COLOR_1 0x30D5C8
# define COLOR_2 0x9B4D96
# define COLOR_3 0xFF7F32

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

typedef struct s_julia
{
	int		x;
	int		y;
	int		iter;
	int		color;
	double	zx;
	double	zy;
}	t_julia;

void	put_pixel(t_data *data, int x, int y, int color);
void	init_data(t_data *data);
void	init_window_and_image(t_data *data);
void	init_fractal(t_data *data, char *fractal);
void	start_fractol(char *fractal);
void	draw_julia(t_data *data);
void	draw_mandelbrot(t_data *data);
void	cleanup(t_data *data);
void	exit_with_error(char *msg);
int	get_color(int iter);
int	handle_keys(int key, t_data *data);
int	handle_mouse(int button, int x, int y, t_data *data);
int	ft_strcmp(char *s1, char *s2);
int	render_frame(t_data *data);
int	clean_exit(t_data *data);

#endif
