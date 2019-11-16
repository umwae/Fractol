/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteuber <jsteuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 18:57:46 by jsteuber          #+#    #+#             */
/*   Updated: 2019/05/29 17:34:52 by jsteuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

static int		blender(int sc1, int sc2, double passed)
{
	return ((1 - passed) * sc1 + passed * sc2);
}

int				getgrad(int color1, int color2, double passed)
{
	int		red;
	int		green;
	int		blue;

	if (color1 == color2)
		return (color1);
	red = blender((color1 >> 16) & 0xFF, (color2 >> 16) & 0xFF, passed);
	green = blender((color1 >> 8) & 0xFF, (color2 >> 8) & 0xFF, passed);
	blue = blender(color1 & 0xFF, color2 & 0xFF, passed);
	return ((red << 16) | (green << 8) | blue);
}

int				getgrad_palette(t_pl *pl, double passed)
{
	int		inum;
	double	partpass;

	inum = passed / pl->part;
	partpass = (passed - (pl->part * inum)) / pl->part;
	if (passed == pl->part)
		partpass = 0;
	if (inum + 1 != pl->amt)
		return (getgrad((pl->cls)[inum], (pl->cls)[inum + 1], partpass));
	return ((pl->cls)[inum]);
}
