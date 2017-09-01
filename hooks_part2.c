/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_part2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoloshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 15:05:07 by dsoloshe          #+#    #+#             */
/*   Updated: 2017/08/17 19:16:38 by dsoloshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		hook_speed_and_shooting(int key, t_fdf *res)
{
	if (key == 49)
	{
		if (res->sw == 0)
			res->sw = 1;
	}
	if (key == 3)
	{
		if (res->sw2 == 0)
			res->sw2 = 1;
	}
	if (key == 126 && res->m_p < 0.5)
		res->m_p += 0.05;
	if (key == 125 && res->m_p >= 0.1)
		res->m_p -= 0.05;
	if (key == 124 && res->r_p < 0.2)
		res->r_p += 0.01;
	if (key == 123 && res->r_p >= 0.1)
		res->r_p -= 0.01;
	return (0);
}

int		change_map(int key, t_fdf *res)
{
	if (key == 18)
	{
		res->m_num = 1;
		reset_params(res);
	}
	if (key == 19)
	{
		res->m_num = 2;
		reset_params(res);
	}
	if (key == 20)
	{
		res->m_num = 3;
		reset_params(res);
	}
	return (0);
}

int		hook_operators(int key, t_fdf *res)
{
	if (key == 53)
		exit(0);
	if (key == 48)
	{
		if (res->text == 0)
			res->text = 1;
		else
			res->text = 0;
	}
	if (key == 49 || key == 3 || (key >= 123 && key <= 126))
		hook_speed_and_shooting(key, res);
	if (key == 13 || key == 1)
		hook_move(key, res);
	if (key == 0 || key == 2)
		hook_rotate(key, res);
	if (key == 15)
		reset_params(res);
	if (key >= 18 && key <= 20)
		change_map(key, res);
	return (0);
}

int		mouse_shoot(int key, int x, int y, t_fdf *res)
{
	x = 0;
	y = 0;
	if (key == 1)
		res->sw = 1;
	return (0);
}
