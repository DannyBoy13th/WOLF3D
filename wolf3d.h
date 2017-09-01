/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoloshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 16:54:45 by dsoloshe          #+#    #+#             */
/*   Updated: 2017/08/17 19:47:50 by dsoloshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
# include "libft/libft.h"
# include "minilibx/mlx.h"
# include "math.h"
# include "fcntl.h"
# define RESO_X 1024
# define RESO_Y 768
# define MAP_X 50
# define MAP_Y 50
# define TS 128

typedef struct	s_images
{
	unsigned int	*img;
	char			*addr;
	int				bpp;
	int				sl;
	int				endl;
}				t_images;

typedef struct	s_fdf
{
	t_images		t[10];
	char			**line;
	void			*mlx;
	void			*win;
	unsigned int	col;
	double			px;
	double			py;
	double			dx;
	double			dy;
	double			pl_x;
	double			pl_y;
	double			camx;
	double			r_px;
	double			r_py;
	double			r_dx;
	double			r_dy;
	int				map[MAP_X][MAP_Y];
	int				mapx;
	int				mapy;
	double			sd_x;
	double			sd_y;
	double			wd;
	int				st_x;
	int				st_y;
	int				hit;
	int				side;
	double			del_x;
	double			del_y;
	int				dr_s;
	int				dr_e;
	int				ln_h;
	double			p_dx;
	double			pr_pl_x;
	void			*pis_r_1;
	void			*pis_r_2;
	void			*pis_r_3;
	void			*pis_l_1;
	void			*pis_l_2;
	void			*pis_l_3;
	void			*kick;
	void			*cross;
	void			*hit1;
	void			*hit2;
	int				t_s;
	int				tilt;
	int				sw;
	int				sw2;
	int				sw3;
	double			ms;
	double			rs;
	double			x;
	double			y;
	double			r_p;
	double			m_p;
	int				tn;
	double			w_x;
	int				texx;
	int				d;
	int				texy;
	int				tn2;
	int				m_num;
	int				fd;
	char			*file;
	int				t_dr_s;
	int				text;
	char			*map_buf;
	char			*temp;
}				t_fdf;

void			mlx_launcher(t_fdf *res);
void			texture_parser(t_fdf *res);
void			ft_put_pix(int y, int x, int color, t_fdf *res);
int				hook_move(int key, t_fdf *res);
int				hook_operators(int key, t_fdf *res);
int				draw_image(t_fdf *res);
int				hook_wait(int key, t_fdf *res);
int				click_x(void *click);
int				mouse_move(int x, int y, t_fdf *res);
int				mouse_shoot(int key, int x, int y, t_fdf *res);
int				hook_rotate(int key, t_fdf *res);
void			load_textures_part1(t_fdf *res);
void			load_textures_part2(t_fdf *res);
void			load_textures_part3(t_fdf *res);
void			reset_params(t_fdf *res);
int				extract_col(int x, int y, t_fdf *res);
void			shot1(t_fdf *res);
void			shot2(t_fdf *res);
void			set_params(int x, t_fdf *res);
void			set_pos(t_fdf *res);
void			calculate_hit(t_fdf *res);
void			calculate_draw_dist(t_fdf *res);
void			draw_sky(int x, t_fdf *res);
void			draw_untextured(int x, t_fdf *res);
void			draw_textures(int x, t_fdf *res);
void			draw_floor(int x, t_fdf *res);
void			gun_stuff(t_fdf *res);
void			operations(int x, t_fdf *res);
int				hook_rotate(int key, t_fdf *res);
int				hook_speed_and_shooting(int key, t_fdf *res);
void			read_map(t_fdf *res);
void			parse_map(t_fdf *res);

#endif
