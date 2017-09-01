/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoloshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 15:04:29 by dsoloshe          #+#    #+#             */
/*   Updated: 2017/08/17 18:53:50 by dsoloshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_put_pix(int y, int x, int color, t_fdf *res)
{
	if (y >= RESO_Y || x >= RESO_X || y <= 0 || x <= 0)
		return ;
	res->t[0].addr[y * res->t[0].sl + x * 4] = color & 0x0000ff;
	res->t[0].addr[y * res->t[0].sl + x * 4 + 1] = (color >> 8) & 0xff;
	res->t[0].addr[y * res->t[0].sl + x * 4 + 2] = (color >> 16);
}

int		extract_col(int x, int y, t_fdf *res)
{
	int	col;
	int	temp;

	temp = (x * 4 + y * res->t[res->tn2].sl);
	col = (res->t[res->tn2].addr[temp + 2]) << 16;
	col += (res->t[res->tn2].addr[temp + 1]) << 8;
	col += (res->t[res->tn2].addr[temp]);
	return (col);
}

void	reset_params(t_fdf *res)
{
	read_map(res);
	parse_map(res);
	res->tilt = 60;
	res->sw = 0;
	res->sw3 = 0;
	res->x = 0.0;
	res->y = 0.0;
	res->text = 0;
	res->px = 22;
	res->py = 11.5;
	res->dx = -1;
	res->dy = 0;
	res->pl_x = 0;
	res->pl_y = 0.66;
}

void	shot1(t_fdf *res)
{
	if (res->sw3 <= 30)
	{
		if (res->sw3 <= 15)
		{
			mlx_put_image_to_window(res->mlx, res->win, res->pis_r_3,
					(RESO_X / 100) * (int)res->tilt, (RESO_Y / 100) * 58);
			mlx_put_image_to_window(res->mlx, res->win, res->pis_l_1,
					(RESO_X / 100), (RESO_Y / 100) * 75);
			res->sw3++;
		}
		else
		{
			mlx_put_image_to_window(res->mlx, res->win, res->pis_l_3,
					(RESO_X / 100), (RESO_Y / 100) * 58);
			mlx_put_image_to_window(res->mlx, res->win, res->pis_r_1,
					(RESO_X / 100) * (int)res->tilt, (RESO_Y / 100) * 75);
			mlx_put_image_to_window(res->mlx, res->win, res->hit2,
					(RESO_X / 2) - 33, (RESO_Y / 2) - 30);
			res->sw3++;
		}
		if (res->sw3 == 30)
			res->sw3 = 0;
	}
}

void	shot2(t_fdf *res)
{
	if (res->sw3 <= 30)
	{
		if (res->sw3 <= 15)
		{
			mlx_put_image_to_window(res->mlx, res->win, res->pis_l_2,
					(RESO_X / 100), (RESO_Y / 100) * 67);
			mlx_put_image_to_window(res->mlx, res->win, res->pis_r_1,
					(RESO_X / 100) * (int)res->tilt, (RESO_Y / 100) * 75);
			res->sw3++;
		}
		else
		{
			mlx_put_image_to_window(res->mlx, res->win, res->pis_r_2,
					(RESO_X / 100) * (int)res->tilt, (RESO_Y / 100) * 67);
			mlx_put_image_to_window(res->mlx, res->win, res->pis_l_1,
					(RESO_X / 100), (RESO_Y / 100) * 75);
			mlx_put_image_to_window(res->mlx, res->win, res->hit1,
					(RESO_X / 2) - 33, (RESO_Y / 2) - 30);
			res->sw3++;
		}
		if (res->sw3 == 30)
			res->sw3 = 0;
	}
}
