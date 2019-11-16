/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteuber <jsteuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 19:00:34 by jsteuber          #+#    #+#             */
/*   Updated: 2019/11/16 15:09:08 by jsteuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

static void		mandelbrot_iterator(t_win *win1, t_wrp w)
{
	int		i;

	i = 0;
	w.passed = 0;
	w.zre = 0;
	w.zim = 0;
	w.zresq = w.zre * w.zre;
	w.zimsq = w.zim * w.zim;
	while (w.zresq + w.zimsq <= SMOOTHNESS && i < win1->i_max)
	{
		w.zim = w.zre * w.zim;
		w.zim += w.zim;
		w.zim += w.cim;
		w.zre = w.zresq - w.zimsq + w.cre;
		w.zresq = w.zre * w.zre;
		w.zimsq = w.zim * w.zim;
		i++;
	}
	if (w.zre * w.zre + w.zim * w.zim < 4)
		return ;
	w.logar = i + 1 - log(log(w.zre * w.zre + w.zim * w.zim)) / log(2);
	w.passed = (w.logar - win1->pl_cycle * floor(w.logar / win1->pl_cycle)) /
														win1->pl_cycle;
	w.color = getgrad_palette(win1->pl, w.passed);
	img_pxl(win1, w);
}

void			mandelbrot(void *td, t_wrp w)
{
	t_win		*win1;

	win1 = (t_win *)(td);
	while (w.yos <= w.end - 1)
	{
		w.xos = 0;
		w.x = 0;
		w.y = w.yos - win1->y_offs;
		while (w.xos <= win1->width - 1)
		{
			w.x = w.xos - win1->x_offs;
			w.cre = 1.5 * (w.x - win1->width / 2) / win1->zoom;
			w.cim = 1.5 * (w.y - win1->hight / 2) / win1->zoom;
			mandelbrot_iterator(win1, w);
			w.xos++;
		}
		w.yos++;
	}
}
