/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteuber <jsteuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 19:28:34 by jsteuber          #+#    #+#             */
/*   Updated: 2019/11/16 15:25:53 by jsteuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"
#include <stdlib.h>
#include <unistd.h>

void		err_ex(int pr)
{
	if (pr == 0)
		ft_putstr("Memory allocation failure\n");
	if (pr == 1)
		ft_putstr("Pthread error\n");
	if (pr == 2)
		ft_putstr("MLX error\n");
	exit(1);
}

t_wrp		**wrap(void)
{
	int				i;
	static t_wrp	**wrp_arr;

	i = 0;
	if (!(wrp_arr = (t_wrp **)malloc(sizeof(t_wrp) * CORES)))
		err_ex(0);
	while (i < CORES)
	{
		if (!(wrp_arr[i] = (t_wrp *)malloc(sizeof(t_wrp))))
			err_ex(0);
		i++;
	}
	return (wrp_arr);
}

void		render(t_win *win1)
{
	pthread_t		self;
	int				th_num;
	t_wrp			w;

	th_num = 0;
	self = pthread_self();
	while (self != win1->th_arr[th_num])
		th_num++;
	w = *(win1->wrp_arr)[th_num];
	w.start = win1->hight / CORES * th_num;
	w.end = w.start + win1->hight / CORES;
	w.yos = w.start;
	w.y = 0;
	(*(win1->fract_ptr))((void *)win1, w);
}

void		threads(void *vp)
{
	int			i;
	t_win		*win1;

	i = 0;
	win1 = (t_win *)vp;
	mlx_clear_window(win1->mlx, win1->win);
	img_fill(win1->image, 0x000000);
	while (i < CORES)
	{
		if (pthread_create(&win1->th_arr[i], NULL,
					(void *)render, win1))
			err_ex(1);
		i++;
	}
	i = 0;
	while (i < CORES)
	{
		if (pthread_join(win1->th_arr[i], NULL))
			err_ex(1);
		i++;
	}
	mlx_put_image_to_window(win1->mlx, win1->win, win1->img_ptr, 0, 0);
}

int			main(int argc, char **argv)
{
	t_win	*win1;

	if (!(win1 = (t_win *)malloc(sizeof(t_win))))
		err_ex(0);
	init(win1);
	parser(win1, argv[1], argc);
	img_new(win1);
	threads(win1);
	hooks(win1);
	return (0);
}
