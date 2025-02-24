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
# include "ft_printf/ft_printf.h"
# include "mlx/mlx.h"

# define WIDTH 800
# define HEIGHT 800
# define MAX_ITER 100
# define COLOR1 0x1E90FF
# define COLOR2 0x228B22
# define COLOR3 0xFFD700

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
int		handle_keys(int key, t_data *data);
int		handle_mouse(int button, int x, int y, t_data *data);
int		render_frame(t_data *data);
int		ft_strcmp(char *s1, char *s2);

#endif