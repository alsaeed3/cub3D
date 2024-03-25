/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:10:21 by mlumibao          #+#    #+#             */
/*   Updated: 2024/03/25 22:22:00 by alsaeed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include <libft.h>
# include <mlx.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <limits.h>
# include <math.h>
# include <stdbool.h>
# include "key_code.h"

# ifdef __linux__
#  include <X11/keysym.h>
# endif

# define WIDTH			1024
# define HEIGHT			768
# define NO				1
# define EA				2
# define WE				3
# define SO				4
# define F				5
# define C				6
# define X				0
# define Y				1
# define MS				0.06 //movespeed
# define RS				0.035 //rotate speed

typedef struct s_draw
{
	int		line_h;
	int		draw_start;
	int		draw_end;
	int		tex_x;
	int		tex_y;
	double	wall_x;
	double	step;
	double	texpos;
}	t_draw;

typedef struct s_player
{
	char	facing;
	int		x;
	int		y;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	mouse_x;
	double	mouse_y;
}	t_player;

typedef struct s_rgb
{
	int		r;
	int		g;
	int		b;
}	t_rgb;

typedef struct s_img
{
	void		*ptr;
	char		*adr;
	char		dir;
	int			endian;
	int			bpp;
	int			len;
	int			width;
	int			height;
}	t_img;

typedef struct s_map
{
	char		**map;
	int			width;
	int			height;
}	t_map;

typedef struct s_tmp
{
	char			*n_path;
	char			*e_path;
	char			*w_path;
	char			*s_path;
	char			*f;
	char			*c;
}	t_tmp;

typedef struct s_ray
{
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
}	t_ray;

typedef struct s_data
{
	void			*mlx_ptr;
	void			*win_ptr;
	t_ray			ray;
	t_map			map;
	t_player		player;
	uint32_t		floorc;
	uint32_t		skyc;
	int				draw_flag;
	t_img			fbuffer;
	t_img			n_img;
	t_img			e_img;
	t_img			w_img;
	t_img			s_img;
	t_rgb			floor;
	t_rgb			sky;
	t_tmp			tmp;
}	t_data;

// init_utils.c
void		xpm_img(t_data *game);
int			ft_space(char c);
int			ft_space_line(char *str);
void		init_tmp(t_data *game);
void		init_rgb(t_data *game);
int			file_line_count(char **av);

// init_game.c
void		*img_ptr(t_data *game);
void		init_errthang(t_data *game);
void		init_mlx_ptr(t_data *game);

// free.c
void		destroy_img(t_data *game);
void		free_array(char **str);
void		free_array_exit(char **tmp, char *str);

// check.c
void		check(char **av, t_data *game);

// get_file.c
void		check_file_content(char **av, t_data *game);

// verify.c
void		check_map_line(t_data *game, int *size);
void		verify_map(t_data *game);
int			check_map_char(t_data *game, int *i);
void		check_map_walls(t_data *game, int size);

// verify_utils.c
char		**ft_split_tab(char const *s, char c);
char		*copy_and_free(char **tmp);
int			count_array(char **s);

// check_elements.c
void		check_elements(t_data *game);
void		store_to_rgb(t_data *game, char *str, int type);
void		check_hex(t_data *game, char **tmp, int type);

// scan_utils.c
void		get_store_map(char **file, t_data *game);
char		**scan_map(char **file);

// element_utils.c
int			check_comma(char *str);
int			check_valid_char(char *str);
long		ft_atol(char *str);

// map_edit.c
void		edit_map(t_data *game);
int			check_enclosed_space(char **map);
int			check_enclosed_zero(char **map);

// map_utils.c
int			count_end_space(char *map);
int			count_line_map(char **map);
int			count_line_col(char **map, int col);

// utils for testing testing_utils.c
// void		print_array(char **str);
void		print_array(char **str);
void		print_tmp(t_data *game);
void		free_tmp(t_data *game);
void		print_rgb(t_data *game);

// check_map_utils.c for checking bounderies of 0 and spaces
int			check_left_right_zero(char **map, int x, int y);
int			check_up_down_zero(char **map, int x, int y);
int			check_left_right_space(char **map, int x, int y);
int			check_up_down_space(char **map, int x, int y);
int			ft_valid_char(char c);

// added latest final_parse.c
void		color(t_data *game);
void		getplayerpos(t_data *game);
void		finaladd(t_data *game);
void		init_ray(t_ray *ray);

// added latest rect_map.c
void		rect_map(t_data *game);

// added latest raycast.c
void		calc_ray(t_data *game);
void		calc_step(t_data *game);
void		dda(t_data *game);
void		draw_ray(t_data *game, t_draw *draw, int i);
void		perp(t_data *game, int i);

// added keymap.c
int			key_rotate(int sign, t_data *game);
int			key_move(int keycode, t_data *game);

// init.c
void		init_mlx(t_data *game);
void		init_player(t_data *game);
void		destroy_img(t_data *game);

void		my_mlx_pixel_put(t_img *img, int x, int y, int color);

// draw_wall.c
void		draw_wall(t_data *game, t_draw *draw, int i);

// wasd_move.c
void		move_w(t_data *game);
void		move_s(t_data *game);
void		move_a(t_data *game);
void		move_d(t_data *game);

// wall_collision.c
bool		check_wall(t_data *game, double x, double y);
int			check_move(t_data *game, double x, double y);

// draw_utils.c
void		init_draw(t_draw *draw);
void		get_direction(t_data *game);

// init_textures.c
void		init_textures(t_data *game);
int			close_game(t_data *game);
void		exit_init(t_data *game, char *str);

#endif