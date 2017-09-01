/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoloshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 15:04:48 by dsoloshe          #+#    #+#             */
/*   Updated: 2017/08/17 19:31:47 by dsoloshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	draw_sky(int x, t_fdf *res)
{
	int j;

	j = 0;
	while (j < res->dr_s)
	{
		res->tn2 = 9;
		if (res->text == 1)
			res->col = extract_col(x, j, res);
		else
			res->col = 0x7fb0ff;
		ft_put_pix(j, x, res->col, res);
		j++;
	}
}

void	draw_untextured(int x, t_fdf *res)
{
	res->t_dr_s = res->dr_s;
	while (res->t_dr_s < res->dr_e)
	{
		if (res->map[res->mapx][res->mapy] == 1)
			res->col = 0xff0000;
		if (res->map[res->mapx][res->mapy] == 2)
			res->col = 0xff;
		if (res->map[res->mapx][res->mapy] == 3)
			res->col = 0x00ff00;
		if (res->map[res->mapx][res->mapy] == 4)
			res->col = 0xffff00;
		if (res->map[res->mapx][res->mapy] == 5)
			res->col = 0xffffff;
		if (res->map[res->mapx][res->mapy] == 6)
			res->col = 0x236726;
		if (res->map[res->mapx][res->mapy] == 7)
			res->col = 0x546323;
		if (res->map[res->mapx][res->mapy] == 8)
			res->col = 0x845345;
		if (res->side == 1)
			res->col = res->col / 1.5;
		ft_put_pix(res->t_dr_s, x, res->col, res);
		res->t_dr_s++;
	}
}

void	draw_textures(int x, t_fdf *res)
{
	res->t_dr_s = res->dr_s;
	res->tn = res->map[res->mapx][res->mapy];
	res->tn2 = res->tn;
	if (res->side == 0)
		res->w_x = res->r_py + res->wd * res->r_dy;
	else
		res->w_x = res->r_px + res->wd * res->r_dx;
	res->w_x -= floor((res->w_x));
	res->texx = (int)(res->w_x * (double)(TS));
	if (res->side == 0 && res->r_dx > 0)
		res->texx = TS - res->texx - 1;
	if (res->side == 1 && res->r_dy < 0)
		res->texx = TS - res->texx - 1;
	res->t_dr_s = res->dr_s;
	while (res->t_dr_s < res->dr_e)
	{
		res->d = res->t_dr_s * 256 - RESO_Y * 128 + res->ln_h * 128;
		res->texy = ((res->d * TS) / res->ln_h) / 256;
		res->col = extract_col(res->texx, res->texy, res);
		if (res->side == 1)
			res->col = (res->col >> 1) & 8355711;
		ft_put_pix(res->t_dr_s, x, res->col, res);
		res->t_dr_s++;
	}
}

void	draw_floor(int x, t_fdf *res)
{
	int i;

	i = res->dr_e;
	while (i < RESO_Y)
	{
		if (res->text == 1)
			res->col = 0x172508;
		else
			res->col = 0x2d1101;
		ft_put_pix(i, x, res->col, res);
		i++;
	}
}

int		draw_image(t_fdf *res)
{
	int x;

	x = 0;
	while (x < RESO_X)
	{
		operations(x, res);
		x++;
	}
	mlx_put_image_to_window(res->mlx, res->win, res->t[0].img, 0, 0);
	mlx_put_image_to_window(res->mlx, res->win, res->cross,
			(RESO_X / 2) - 20, (RESO_Y / 2) - 25);
	if (res->sw == 0)
	{
		mlx_put_image_to_window(res->mlx, res->win, res->pis_r_1,
				(RESO_X / 100) * (int)res->tilt, (RESO_Y / 100) * 75);
		mlx_put_image_to_window(res->mlx, res->win, res->pis_l_1,
				(RESO_X / 100), (RESO_Y / 100) * 75);
	}
	gun_stuff(res);
	return (0);
}
