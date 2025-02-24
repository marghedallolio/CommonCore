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
