/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteuber <jsteuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 18:52:28 by jsteuber          #+#    #+#             */
/*   Updated: 2019/11/16 15:15:12 by jsteuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H

# include "./libft/includes/libft.h"
# include <pthread.h>
# include <math.h>
# include "mlx.h"

typedef struct		s_wrp
{
	double			cre;
	double			cim;
	double			zre;
	double			zim;
	double			x;
	double			y;
	int				xos;
	int				yos;
	int				color;
	int				start;
	int				end;
	double			zresq;
	double			zimsq;
	double			passed;
	double			logar;

}					t_wrp;

typedef struct		s_pl
{
	int				*cls;
	int				amt;
	double			part;
}					t_pl;

typedef struct		s_win
{
	void			(*fract_ptr)(void *, t_wrp);
	void			*mlx;
	void			*win;
	int				width;
	int				hight;
	double			zoom;
	t_wrp			**wrp_arr;
	double			i_max;
	char			*img_ptr;
	void			*image;
	int				linesize;
	double			x_offs;
	double			y_offs;
	int				pl_cycle;
	t_pl			*pl;
	int				th_num;
	pthread_t		*th_arr;
	int				dragl;
	int				dragr;
	double			x_mem;
	double			y_mem;
	int				i_fact;
	double			cre_start;
	double			cim_start;
}					t_win;

# define WIN_WIDTH 700
# define WIN_HIGHT 700
# define START_ZOOM 150
# define START_I_MAX 20
# define I_FACT 2
# define PL_CYCLE 30
# define ARROWS_STEP 20
# define CORES 8
# define SMOOTHNESS 200

void				init(t_win *win1);
void				hooks(t_win *win1);
t_wrp				**wrap(void);
void				img_new(t_win *win1);
void				img_pxl(t_win *win1, t_wrp w);
void				img_fill(void *idata, int color);
void				err_ex(int pr);
int					getgrad(int color1, int color2, double passed);
int					getgrad_palette(t_pl *plw, double passed);
void				pl_create_ultra(t_win *win1);
void				pl_create_red(t_win *win1);
void				pl_create_pb(t_win *win1);
int					key_action(int keycode, t_win *win1);
void				key_action2(int keycode, t_win *win1);
int					mouse_press(int button, int x, int y, t_win *win1);
int					mouse_release(int button, int x, int y, t_win *win1);
int					mouse_move(int x, int y, t_win *win1);
void				mandelbrot(void *td, t_wrp w);
void				julia(void *td, t_wrp w);
void				burning_ship(void *td, t_wrp w);
void				render(t_win *win1);
void				threads(void *vp);
void				parser(t_win *win1, char *fract, int argc);

#endif
