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

int handle_keys(int key, t_data *data)
{
    if (key == 65307)
        cleanup(data);
    return (0);
}

int	handle_mouse(int button, int x, int y, t_data *data)
{
<<<<<<< HEAD
	double	mouse_x;
	double	mouse_y;
	double	zoom_factor;

	if (!data || !data->fractal)
		return (0);

	// Converti la posizione del mouse nel sistema di coordinate del frattale
	mouse_x = (x - WIDTH / 2.0) * 4.0 / WIDTH * data->zoom + data->move_x;
	mouse_y = (y - HEIGHT / 2.0) * 4.0 / HEIGHT * data->zoom + data->move_y;

	if (button == 4) // Zoom in
		zoom_factor = 1.1;
	else if (button == 5) // Zoom out
		zoom_factor = 1 / 1.1;
	else
		return (0);

	// Aggiorna lo zoom
	data->zoom *= zoom_factor;

	// Modifica move_x e move_y per mantenere il punto sotto il mouse fisso
	data->move_x = mouse_x - (x - WIDTH / 2.0) * 4.0 / WIDTH * data->zoom;
	data->move_y = mouse_y - (y - HEIGHT / 2.0) * 4.0 / HEIGHT * data->zoom;

	data->needs_redraw = 1; // Indica che bisogna ridisegnare
=======
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
>>>>>>> ab1c3f48ff4c0145ab475810f7bf994c41915558
	return (0);
}



