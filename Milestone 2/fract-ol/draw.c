/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdalloli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:14:20 by mdalloli          #+#    #+#             */
/*   Updated: 2025/02/12 11:14:29 by mdalloli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixel(t_data *data, int x, int y, int color)
{
	char	*pxl;

	if (!data->addr)
		return ;
	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		pxl = data->addr + (y * data->line_len + x * (data->bpp / 8));
		*(unsigned int *)pxl = color;
	}
}

int	get_color(int iter)
{
	return (iter * 255 * 255 * 255 * 255 / 100);
}
