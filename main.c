/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoloshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 16:40:14 by dsoloshe          #+#    #+#             */
/*   Updated: 2017/08/17 18:44:49 by dsoloshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	mlx_launcher(t_fdf *res)
{
	res->t_s = TS;
	res->mlx = mlx_init();
	res->win = mlx_new_window(res->mlx, RESO_X, RESO_Y, "wolf3d");
	res->t[0].img = mlx_new_image(res->mlx, RESO_X, RESO_Y);
	res->t[0].addr = mlx_get_data_addr(res->t[0].img,
			&res->t[0].bpp, &res->t[0].sl, &res->t[0].endl);
	mlx_hook(res->win, 2, 1L << 0, &hook_operators, res);
	mlx_hook(res->win, 3, 1L << 1, &hook_wait, res);
	mlx_hook(res->win, 17, 1L << 17, &click_x, res);
	mlx_mouse_hook(res->win, &mouse_shoot, res);
	mlx_hook(res->win, 6, 3, mouse_move, res);
	mlx_loop_hook(res->mlx, &draw_image, res);
	load_textures_part1(res);
	load_textures_part2(res);
	load_textures_part3(res);
	reset_params(res);
	draw_image(res);
}

void	operations(int x, t_fdf *res)
{
	set_params(x, res);
	set_pos(res);
	calculate_hit(res);
	calculate_draw_dist(res);
	draw_sky(x, res);
	if (res->text == 0)
		draw_untextured(x, res);
	else
		draw_textures(x, res);
	draw_floor(x, res);
}

void	read_map(t_fdf *res)
{
	res->map_buf = ft_strnew(2000);
	if (res->m_num == 1)
		res->fd = open("maps/map1", O_RDONLY);
	if (res->m_num == 2)
		res->fd = open("maps/map2", O_RDONLY);
	if (res->m_num == 3)
		res->fd = open("maps/map3", O_RDONLY);
	read(res->fd, res->map_buf, 2000);
}

void	parse_map(t_fdf *res)
{
	int i;
	int j;
	int t;

	i = 0;
	t = 0;
	while (res->map_buf[i] != '\n' && res->map_buf[i + 1] != '\n')
	{
		j = 0;
		while (res->map_buf[i] != '\n')
		{
			res->map[t][j] = res->map_buf[i] - '0';
			j++;
			i++;
		}
		t++;
		i++;
	}
	free(res->map_buf);
}

int		main(void)
{
	static	t_fdf res;

	res.m_num = 1;
	read_map(&res);
	parse_map(&res);
	mlx_launcher(&res);
	mlx_loop(res.mlx);
	return (0);
}
