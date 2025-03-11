/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdalloli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 10:52:02 by mdalloli          #+#    #+#             */
/*   Updated: 2025/02/12 10:52:03 by mdalloli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_printf("Usa: ./fractol mandelbrot | julia\n");
		exit(1);
	}
	start_fractol(argv[1]);
	return (0);
}
