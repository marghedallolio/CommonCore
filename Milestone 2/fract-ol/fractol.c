/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdalloli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 14:48:55 by mdalloli          #+#    #+#             */
/*   Updated: 2025/03/11 14:48:56 by mdalloli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_data(t_data *data)
{
	data->zoom = 1.0;
	data->move_x = 0.0;
	data->move_y = 0.0;
	data->max_iter = MAX_ITER;
	data->needs_redraw = 1;
}

void	init_window_and_image(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		exit_with_error("Errore inizializzazione MiniLibX");
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, data->fractal);
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
