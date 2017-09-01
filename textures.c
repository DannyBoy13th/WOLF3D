/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoloshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 15:04:19 by dsoloshe          #+#    #+#             */
/*   Updated: 2017/08/17 19:06:34 by dsoloshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	load_textures_part1(t_fdf *res)
{
	res->t[1].img = mlx_xpm_file_to_image(res->mlx, "xpm/t1.xpm",
			&res->t_s, &res->t_s);
	res->t[2].img = mlx_xpm_file_to_image(res->mlx, "xpm/t6.xpm",
			&res->t_s, &res->t_s);
	res->t[3].img = mlx_xpm_file_to_image(res->mlx, "xpm/t3.xpm",
			&res->t_s, &res->t_s);
	res->t[4].img = mlx_xpm_file_to_image(res->mlx, "xpm/t4.xpm",
			&res->t_s, &res->t_s);
	res->t[5].img = mlx_xpm_file_to_image(res->mlx, "xpm/t5.xpm",
			&res->t_s, &res->t_s);
	res->t[6].img = mlx_xpm_file_to_image(res->mlx, "xpm/t2.xpm",
			&res->t_s, &res->t_s);
	res->t[7].img = mlx_xpm_file_to_image(res->mlx, "xpm/t7.xpm",
			&res->t_s, &res->t_s);
	res->t[8].img = mlx_xpm_file_to_image(res->mlx, "xpm/t8.xpm",
			&res->t_s, &res->t_s);
	res->t[9].img = mlx_xpm_file_to_image(res->mlx, "xpm/sky.xpm",
			&res->t_s, &res->t_s);
}

void	load_textures_part2(t_fdf *res)
{
	res->t[1].addr = mlx_get_data_addr(res->t[1].img,
			&res->t[1].bpp, &res->t[1].sl, &res->t[1].endl);
	res->t[2].addr = mlx_get_data_addr(res->t[2].img,
			&res->t[2].bpp, &res->t[2].sl, &res->t[2].endl);
	res->t[3].addr = mlx_get_data_addr(res->t[3].img,
			&res->t[3].bpp, &res->t[3].sl, &res->t[3].endl);
	res->t[4].addr = mlx_get_data_addr(res->t[4].img,
			&res->t[4].bpp, &res->t[4].sl, &res->t[4].endl);
	res->t[5].addr = mlx_get_data_addr(res->t[5].img,
			&res->t[5].bpp, &res->t[5].sl, &res->t[5].endl);
	res->t[6].addr = mlx_get_data_addr(res->t[6].img,
			&res->t[6].bpp, &res->t[6].sl, &res->t[6].endl);
	res->t[7].addr = mlx_get_data_addr(res->t[7].img,
			&res->t[7].bpp, &res->t[7].sl, &res->t[7].endl);
	res->t[8].addr = mlx_get_data_addr(res->t[8].img,
			&res->t[8].bpp, &res->t[8].sl, &res->t[8].endl);
	res->t[9].addr = mlx_get_data_addr(res->t[9].img,
			&res->t[9].bpp, &res->t[9].sl, &res->t[9].endl);
}

void	load_textures_part3(t_fdf *res)
{
	res->pis_r_1 = mlx_xpm_file_to_image(res->mlx,
			"xpm/Pistol_R_1.xpm", &res->t_s, &res->t_s);
	res->pis_r_2 = mlx_xpm_file_to_image(res->mlx,
			"xpm/Pistol_R_2.xpm", &res->t_s, &res->t_s);
	res->pis_r_3 = mlx_xpm_file_to_image(res->mlx,
			"xpm/Pistol_R_3.xpm", &res->t_s, &res->t_s);
	res->pis_l_1 = mlx_xpm_file_to_image(res->mlx,
			"xpm/Pistol_L_1.xpm", &res->t_s, &res->t_s);
	res->pis_l_2 = mlx_xpm_file_to_image(res->mlx,
			"xpm/Pistol_L_2.xpm", &res->t_s, &res->t_s);
	res->pis_l_3 = mlx_xpm_file_to_image(res->mlx,
			"xpm/Pistol_L_3.xpm", &res->t_s, &res->t_s);
	res->kick = mlx_xpm_file_to_image(res->mlx,
			"xpm/kick.xpm", &res->t_s, &res->t_s);
	res->cross = mlx_xpm_file_to_image(res->mlx,
			"xpm/cross.xpm", &res->t_s, &res->t_s);
	res->hit1 = mlx_xpm_file_to_image(res->mlx,
			"xpm/hit1.xpm", &res->t_s, &res->t_s);
	res->hit2 = mlx_xpm_file_to_image(res->mlx,
			"xpm/hit2.xpm", &res->t_s, &res->t_s);
}
