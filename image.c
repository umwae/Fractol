/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteuber <jsteuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 18:58:08 by jsteuber          #+#    #+#             */
/*   Updated: 2019/11/16 15:19:58 by jsteuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void		img_new(t_win *win1)
{
	char	*img;
	int		bpp;
	int		endian;

	if (!(img = mlx_new_image(win1->mlx, win1->width, win1->hight)))
		err_ex(2);
	win1->image = mlx_get_data_addr(img, &bpp, &(win1->linesize), &endian);
	win1->img_ptr = img;
}

void		img_pxl(t_win *win1, t_wrp w)
{
	char	*p;

	p = win1->image;
	p += (w.xos * 32 / 8) + (win1->linesize * w.yos);
	*p++ = (w.color) & 0xFF;
	*p++ = (w.color >> 8) & 0xFF;
	*p = (w.color >> 16) & 0xFF;
}

void		img_fill(void *idata, int color)
{
	int		*p;
	int		xl;
	int		yl;

	p = (int *)idata;
	yl = WIN_HIGHT;
	while (yl--)
	{
		xl = WIN_WIDTH;
		while (xl--)
			*p++ = color;
	}
}
