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

# define COLOR1 0x1E90FF // Blu
# define COLOR2 0x228B22  // Verde
# define COLOR3 0xFFD700  // Giallo


typedef struct s_data
{
    void    *mlx;       // Puntatore a MiniLibX
    void    *win;       // Finestra MiniLibX
    void    *img;       // Immagine MiniLibX
    char    *addr;      // Indirizzo della memoria dell'immagine
    int     bpp;
    int     line_len;
    int     endian;
    double  zoom;       // Zoom
    double  move_x;     // Spostamento sull'asse X
    double  move_y;     // Spostamento sull'asse Y
    int     max_iter;   // Numero massimo di iterazioni
    double  julia_cx;   // Parametro Cx per Julia
    double  julia_cy;   // Parametro Cy per Julia
    char    *fractal;   // Tipo di frattale
}   t_data;

void	start_fractol(char *fractal);
void	draw_mandelbrot(t_data *data);
void	draw_julia(t_data *data);
void	put_pixel(t_data *data, int x, int y, int color);
int		handle_keys(int key);
int		handle_mouse(int button, int x, int y, t_data *data);
int		ft_strcmp(char *s1, char *s2);

#endif
