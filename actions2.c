/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteuber <jsteuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 17:39:34 by jsteuber          #+#    #+#             */
/*   Updated: 2019/05/28 21:06:50 by jsteuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void		key_action2(int keycode, t_win *win1)
{
	if (keycode == 33)
	{
		win1->i_max -= 10;
		if (win1->i_max < 8)
			win1->i_max = 8;
	}
	else if (keycode == 30)
		win1->i_max += 10;
	else if (keycode == 123)
		win1->x_offs += 20;
	else if (keycode == 124)
		win1->x_offs -= 20;
	else if (keycode == 125)
		win1->y_offs -= 20;
	else if (keycode == 126)
		win1->y_offs += 20;
	else if (keycode == 83)
		win1->fract_ptr = &mandelbrot;
	else if (keycode == 84)
		win1->fract_ptr = &julia;
	else if (keycode == 85)
		win1->fract_ptr = &burning_ship;
}
