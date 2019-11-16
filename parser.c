/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteuber <jsteuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 19:30:31 by jsteuber          #+#    #+#             */
/*   Updated: 2019/05/29 17:55:44 by jsteuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"
#include <stdlib.h>
#include <unistd.h>

void	parser(t_win *win1, char *fract, int argc)
{
	if (argc > 1 && (ft_strncmp(fract, "mandelbrot", 11) == 0))
		win1->fract_ptr = &mandelbrot;
	else if (argc > 1 && ft_strncmp(fract, "julia", 6) == 0)
	{
		win1->fract_ptr = &julia;
		win1->zoom = 400;
		win1->dragr = 1;
	}
	else if (argc > 1 && ft_strncmp(fract, "burning_ship", 13) == 0)
	{
		win1->fract_ptr = &burning_ship;
		win1->pl_cycle = 100;
		win1->i_fact = 1;
	}
	else
	{
		ft_putstr("usage: ./fractol fractal_type\n");
		ft_putstr("fractals: mandelbrot, julia, burning_ship\n");
		exit(0);
	}
}
