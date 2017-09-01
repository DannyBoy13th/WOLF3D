/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_part2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoloshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 15:04:38 by dsoloshe          #+#    #+#             */
/*   Updated: 2017/08/17 19:38:34 by dsoloshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	set_params(int x, t_fdf *res)
{
	res->camx = 2 * x / (double)(RESO_X) - 1;
	res->r_px = res->px;
	res->r_py = res->py;
	res->r_dx = res->dx + res->pl_x * res->camx;
	res->r_dy = res->dy + res->pl_y * res->camx;
	res->mapx = (int)(res->r_px);
	res->mapy = (int)(res->r_py);
	res->del_x = sqrt(1 + (res->r_dy * res->r_dy) / (res->r_dx * res->r_dx));
	res->del_y = sqrt(1 + (res->r_dx * res->r_dx) / (res->r_dy * res->r_dy));
	res->hit = 0;
}

void	set_pos(t_fdf *res)
{
	if (res->r_dx < 0)
	{
		res->st_x = -1;
		res->sd_x = (res->r_px - res->mapx) * res->del_x;
	}
	else
	{
		res->st_x = 1;
		res->sd_x = (res->mapx + 1.0 - res->r_px) * res->del_x;
	}
	if (res->r_dy < 0)
	{
		res->st_y = -1;
		res->sd_y = (res->r_py - res->mapy) * res->del_y;
	}
	else
	{
		res->st_y = 1;
		res->sd_y = (res->mapy + 1.0 - res->r_py) * res->del_y;
	}
}

void	calculate_hit(t_fdf *res)
{
	while (res->hit == 0)
	{
		if (res->sd_x < res->sd_y)
		{
			res->sd_x += res->del_x;
			res->mapx += res->st_x;
			res->side = 0;
		}
		else
		{
			res->sd_y += res->del_y;
			res->mapy += res->st_y;
			res->side = 1;
		}
		if (res->map[res->mapx][res->mapy] > 0)
			res->hit = 1;
	}
}

void	calculate_draw_dist(t_fdf *res)
{
	if (res->side == 0)
		res->wd = (res->mapx - res->r_px + (1 - res->st_x) / 2) / res->r_dx;
	else
		res->wd = (res->mapy - res->r_py + (1 - res->st_y) / 2) / res->r_dy;
	res->ln_h = (int)(RESO_Y / res->wd);
	res->dr_s = -res->ln_h / 2 + RESO_Y / 2;
	if (res->dr_s < 0)
		res->dr_s = 0;
	res->dr_e = res->ln_h / 2 + RESO_Y / 2;
	if (res->dr_e >= RESO_Y)
		res->dr_e = RESO_Y - 1;
}

void	gun_stuff(t_fdf *res)
{
	if (res->sw >= 1 && res->sw <= 15)
	{
		res->sw += 1;
		if (res->sw >= 0 && res->sw <= 7)
			shot2(res);
		else
			shot1(res);
		if (res->sw == 15)
			res->sw = 0;
	}
	if (res->sw2 >= 1 && res->sw2 <= 15)
	{
		if (res->sw2 < 8)
			mlx_put_image_to_window(res->mlx, res->win, res->kick,
					(RESO_X / 100) * 40, (RESO_Y / 100) * 80);
		else
			mlx_put_image_to_window(res->mlx, res->win, res->kick,
					(RESO_X / 100) * 40, (RESO_Y / 100) * 50);
		res->sw2 += 1;
		if (res->sw2 == 15)
			res->sw2 = 0;
	}
}
