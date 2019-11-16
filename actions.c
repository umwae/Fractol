/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteuber <jsteuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 17:39:26 by jsteuber          #+#    #+#             */
/*   Updated: 2019/05/29 17:33:10 by jsteuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"
#include <stdlib.h>

int			mouse_move(int x, int y, t_win *win1)
{
	if (win1->dragl == 1)
	{
		win1->x_offs += x - win1->x_mem;
		win1->y_offs += y - win1->y_mem;
		win1->x_mem = x;
		win1->y_mem = y;
	}
	else if (win1->dragr == 1)
	{
		win1->cre_start += (x - win1->x_mem) / win1->zoom;
		win1->cim_start += (y - win1->y_mem) / win1->zoom;
		win1->x_mem = x;
		win1->y_mem = y;
	}
	else
		return (0);
	threads(win1);
	return (0);
}

int			mouse_release(int button, int x, int y, t_win *win1)
{
	if (button == 1)
		win1->dragl = 0;
	else if (button == 2)
		win1->dragr = 0;
	return (0);
	(void)x;
	(void)y;
}

static void	mouse_press2(int button, int x, int y, t_win *win1)
{
	if (button == 1)
	{
		win1->x_mem = x;
		win1->y_mem = y;
		win1->dragl = 1;
	}
	else if (button == 2)
	{
		win1->x_mem = x;
		win1->y_mem = y;
		win1->dragr = 1;
	}
}

int			mouse_press(int button, int x, int y, t_win *win1)
{
	if (button == 5)
	{
		win1->x_mem = win1->width / 2;
		win1->y_mem = win1->hight / 2;
		win1->zoom += win1->zoom / 2;
		win1->x_offs += (win1->x_offs / 2 - (x - win1->x_mem) / 2);
		win1->y_offs += (win1->y_offs / 2 - (y - win1->y_mem) / 2);
		if (win1->zoom > 300)
			win1->i_max += win1->i_fact;
	}
	else if (button == 4)
	{
		win1->x_mem = win1->width / 2;
		win1->y_mem = win1->hight / 2;
		win1->zoom -= win1->zoom / 3;
		win1->x_offs -= win1->x_offs / 3 - (x - win1->x_mem) / 3;
		win1->y_offs -= win1->y_offs / 3 - (y - win1->y_mem) / 3;
		if (win1->zoom > 300)
			win1->i_max -= win1->i_fact;
	}
	else
		mouse_press2(button, x, y, win1);
	threads(win1);
	return (0);
}

int			key_action(int keycode, t_win *win1)
{
	if (keycode == 53)
		exit(0);
	else if (keycode == 18)
	{
		free(win1->pl->cls);
		free(win1->pl);
		pl_create_ultra(win1);
	}
	else if (keycode == 19)
	{
		free(win1->pl->cls);
		free(win1->pl);
		pl_create_red(win1);
	}
	else if (keycode == 20)
	{
		free(win1->pl->cls);
		free(win1->pl);
		pl_create_pb(win1);
	}
	else
		key_action2(keycode, win1);
	threads(win1);
	return (0);
}
