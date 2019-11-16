/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palettes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteuber <jsteuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 18:55:01 by jsteuber          #+#    #+#             */
/*   Updated: 2019/05/29 17:41:39 by jsteuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"
#include <stdlib.h>

void				pl_create_ultra(t_win *win1)
{
	t_pl	*p;

	if (!(win1->pl = (t_pl *)malloc(sizeof(t_pl))))
		err_ex(0);
	p = win1->pl;
	p->amt = 6;
	if (!(p->cls = (int *)malloc(sizeof(int) * p->amt + 1)))
		err_ex(0);
	p->part = 1 / ((double)p->amt - 1);
	(p->cls)[0] = 0x000764;
	(p->cls)[1] = 0x206BCB;
	(p->cls)[2] = 0xEDFFFF;
	(p->cls)[3] = 0xFFAA00;
	(p->cls)[4] = 0x000200;
	(p->cls)[5] = 0x000764;
	(p->cls)[6] = -1;
}

void				pl_create_pb(t_win *win1)
{
	t_pl	*p;

	if (!(win1->pl = (t_pl *)malloc(sizeof(t_pl))))
		err_ex(0);
	p = win1->pl;
	p->amt = 6;
	if (!(p->cls = (int *)malloc(sizeof(int) * p->amt + 1)))
		err_ex(0);
	p->part = 1 / ((double)p->amt - 1);
	(p->cls)[0] = 0x765d5d;
	(p->cls)[1] = 0xf9f37c;
	(p->cls)[2] = 0xff9b35;
	(p->cls)[3] = 0xbd370a;
	(p->cls)[4] = 0x5e0000;
	(p->cls)[5] = 0x765d5d;
	(p->cls)[6] = -1;
}

void				pl_create_red(t_win *win1)
{
	t_pl	*p;

	if (!(win1->pl = (t_pl *)malloc(sizeof(t_pl))))
		err_ex(0);
	p = win1->pl;
	p->amt = 3;
	if (!(p->cls = (int *)malloc(sizeof(int) * p->amt + 1)))
		err_ex(0);
	p->part = 1 / ((double)p->amt - 1);
	(p->cls)[0] = 0x000200;
	(p->cls)[1] = 0xff0000;
	(p->cls)[2] = 0x000200;
	(p->cls)[3] = -1;
}
