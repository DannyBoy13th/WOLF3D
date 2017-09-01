/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoloshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 15:04:56 by dsoloshe          #+#    #+#             */
/*   Updated: 2017/08/17 19:11:43 by dsoloshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		hook_move(int key, t_fdf *res)
{
	res->ms = 0.20 + res->m_p;
	if (key == 13)
	{
		if (!(res->map[(int)(res->px + res->dx)][(int)(res->py)]))
			res->px += res->dx * res->ms;
		if (!(res->map[(int)(res->px)][(int)(res->py + res->dy)]))
			res->py += res->dy * res->ms;
	}
	if (key == 1)
	{
		if (!(res->map[(int)(res->px - res->dx)][(int)(res->py)]))
			res->px -= res->dx * res->ms;
		if (!(res->map[(int)(res->px)][(int)(res->py - res->dy)]))
			res->py -= res->dy * res->ms;
	}
	return (0);
}

int		hook_rotate(int key, t_fdf *res)
{
	res->rs = 0.040 + res->r_p;
	if (key == 2)
	{
		res->p_dx = res->dx;
		res->dx = res->dx * cos(-res->rs) - res->dy * sin(-res->rs);
		res->dy = res->p_dx * sin(-res->rs) + res->dy * cos(-res->rs);
		res->pr_pl_x = res->pl_x;
		res->pl_x = res->pl_x * cos(-res->rs) - res->pl_y * sin(-res->rs);
		res->pl_y = res->pr_pl_x * sin(-res->rs) +
			res->pl_y * cos(-res->rs);
	}
	if (key == 0)
	{
		res->p_dx = res->dx;
		res->dx = res->dx * cos(res->rs) - res->dy * sin(res->rs);
		res->dy = res->p_dx * sin(res->rs) + res->dy * cos(res->rs);
		res->pr_pl_x = res->pl_x;
		res->pl_x = res->pl_x * cos(res->rs) - res->pl_y * sin(res->rs);
		res->pl_y = res->pr_pl_x * sin(res->rs) + res->pl_y * cos(res->rs);
	}
	return (0);
}

int		click_x(void *click)
{
	click = NULL;
	exit(1);
	return (0);
}

int		hook_wait(int key, t_fdf *res)
{
	if (key == 13 || key == 1)
	{
		res->ms = 0;
	}
	if (key == 2 || key == 0)
	{
		res->rs = 0;
	}
	if (key == 3)
		res->sw2 = 0;
	return (0);
}

int		mouse_move(int x, int y, t_fdf *res)
{
	res->y = y;
	res->rs = 0.050;
	if (res->x < x - 2 && x < RESO_X && y > 0 && y < RESO_Y)
	{
		res->p_dx = res->dx;
		res->dx = res->dx * cos(-res->rs) - res->dy * sin(-res->rs);
		res->dy = res->p_dx * sin(-res->rs) + res->dy * cos(-res->rs);
		res->pr_pl_x = res->pl_x;
		res->pl_x = res->pl_x * cos(-res->rs) - res->pl_y * sin(-res->rs);
		res->pl_y = res->pr_pl_x * sin(-res->rs) + res->pl_y * cos(-res->rs);
		res->x = x;
	}
	if (res->x > x + 2 && x > 0 && y < RESO_Y && y > 0)
	{
		res->p_dx = res->dx;
		res->dx = res->dx * cos(res->rs) - res->dy * sin(res->rs);
		res->dy = res->p_dx * sin(res->rs) + res->dy * cos(res->rs);
		res->pr_pl_x = res->pl_x;
		res->pl_x = res->pl_x * cos(res->rs) - res->pl_y * sin(res->rs);
		res->pl_y = res->pr_pl_x * sin(res->rs) + res->pl_y * cos(res->rs);
		res->x = x;
	}
	draw_image(res);
	return (0);
}
