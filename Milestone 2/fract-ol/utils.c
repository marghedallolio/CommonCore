/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdalloli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 10:52:42 by mdalloli          #+#    #+#             */
/*   Updated: 2025/02/12 10:52:44 by mdalloli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double	handle_fraction(const char **str)
{
	double	fraction;
	int		divisor;

	fraction = 0.0;
	divisor = 1;
	(*str)++;
	while (ft_isdigit(**str))
	{
		fraction = fraction * 10.0 + (**str - '0');
		divisor *= 10;
		(*str)++;
	}
	return (fraction / divisor);
}

/*converte una stringa in un numero double*/
double	ft_strtod(const char *str, char **endptr)
{
	double	result;
	int		sign;

	result = 0.0;
	sign = 1;
	while (*str == ' ' || *str == '\t')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-' )
			sign = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		result = result * 10.0 + (*str - '0');
		str++;
	}
	if (*str == '.')
		result += handle_fraction(&str);
	if (endptr)
		*endptr = (char *)str;
	return (result * sign);
}

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
		if (data->fractal && !ft_strcmp(data->fractal, "mandelbrot"))
			draw_mandelbrot(data);
		else if (data->fractal && !ft_strcmp(data->fractal, "julia"))
			draw_julia(data);
		mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
		data->needs_redraw = 0;
	}
	return (0);
}

void	cleanup(t_data *data)
{
	if (data->img)
	{
		mlx_destroy_image(data->mlx, data->img);
		data->img = NULL;
	}
	if (data->win)
	{
		mlx_destroy_window(data->mlx, data->win);
		data->win = NULL;
	}
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		data->mlx = NULL;
	}
}
