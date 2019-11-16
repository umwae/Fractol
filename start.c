/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteuber <jsteuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 19:00:26 by jsteuber          #+#    #+#             */
/*   Updated: 2019/05/29 17:49:26 by jsteuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"
#include <stdlib.h>

void		init(t_win *win1)
{
	win1->width = WIN_WIDTH;
	win1->hight = WIN_HIGHT;
	win1->zoom = START_ZOOM;
	win1->i_fact = I_FACT;
	win1->i_max = START_I_MAX;
	win1->pl_cycle = PL_CYCLE;
	if (!(win1->mlx = mlx_init(win1->hight)))
		err_ex(2);
	win1->win = mlx_new_window(win1->mlx, win1->width, win1->hight, "Fractal");
	if (!win1->win)
		err_ex(2);
	if (!(win1->th_arr = (pthread_t *)malloc(sizeof(pthread_t) * CORES)))
		err_ex(0);
	win1->wrp_arr = wrap();
	pl_create_ultra(win1);
}

void		hooks(t_win *win1)
{
	mlx_hook(win1->win, 4, 1, mouse_press, win1);
	mlx_hook(win1->win, 5, 1, mouse_release, win1);
	mlx_hook(win1->win, 6, 1, mouse_move, win1);
	mlx_hook(win1->win, 2, 1, key_action, win1);
	mlx_loop(win1->mlx);
}
