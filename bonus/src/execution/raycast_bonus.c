/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlumibao <mlumibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:46:16 by mlumibao          #+#    #+#             */
/*   Updated: 2024/03/25 08:02:47 by mlumibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	draw_ray(t_data *game, t_draw *draw, int i)
{
	int	y;

	y = 0;
	while (y < draw->draw_start)
	{
		my_mlx_pixel_put(&game->fbuffer, i, y, game->skyc);
		y++;
	}
	draw_wall(game, draw, i);
	y = draw->draw_end;
	while (y < HEIGHT - 1)
	{
		my_mlx_pixel_put(&game->fbuffer, i, y, game->floorc);
		y++;
	}
	game->draw_flag = 0;
}

void	perp(t_data *game, int i)
{
	t_draw	draw;

	init_draw(&draw);
	if (game->ray.side == 0)
		game->ray.perp_wall_dist = (game->ray.side_dist_x \
		- game->ray.delta_dist_x);
	else
		game->ray.perp_wall_dist = (game->ray.side_dist_y \
		- game->ray.delta_dist_y);
	draw.line_h = (int)(HEIGHT / game->ray.perp_wall_dist);
	draw.draw_start = -draw.line_h / 2 + HEIGHT / 2;
	if (draw.draw_start < 0)
		draw.draw_start = 0;
	draw.draw_end = draw.line_h / 2 + HEIGHT / 2;
	if (draw.draw_end >= HEIGHT)
		draw.draw_end = HEIGHT - 1;
	if (game->ray.side == 0)
		draw.wall_x = game->player.pos_y + game->ray.perp_wall_dist \
		* game->ray.ray_dir_y;
	else
		draw.wall_x = game->player.pos_x + game->ray.perp_wall_dist \
		* game->ray.ray_dir_x;
	draw.wall_x -= floor(draw.wall_x);
	draw_ray(game, &draw, i);
}

void	dda(t_data *game)
{
	while (game->ray.hit == 0)
	{
		if (game->ray.side_dist_x < game->ray.side_dist_y)
		{
			game->ray.side_dist_x += game->ray.delta_dist_x;
			game->ray.map_x += game->ray.step_x;
			game->ray.side = 0;
		}
		else
		{
			game->ray.side_dist_y += game->ray.delta_dist_y;
			game->ray.map_y += game->ray.step_y;
			game->ray.side = 1;
		}
		if (game->map.map[game->ray.map_x][game->ray.map_y] == '1')
			game->ray.hit = 1;
	}
}

void	calc_step(t_data *game)
{
	if (game->ray.ray_dir_x < 0)
	{
		game->ray.step_x = -1;
		game->ray.side_dist_x = (game->player.pos_x - game->ray.map_x) \
		* game->ray.delta_dist_x;
	}
	else
	{
		game->ray.step_x = 1;
		game->ray.side_dist_x = (game->ray.map_x + 1.0 - game->player.pos_x) \
		* game->ray.delta_dist_x;
	}
	if (game->ray.ray_dir_y < 0)
	{
		game->ray.step_y = -1;
		game->ray.side_dist_y = (game->player.pos_y - game->ray.map_y) \
		* game->ray.delta_dist_y;
	}
	else
	{
		game->ray.step_y = 1;
		game->ray.side_dist_y = (game->ray.map_y + 1.0 - game->player.pos_y) \
		* game->ray.delta_dist_y;
	}
}

void	calc_ray(t_data *game)
{
	int	i;

	i = 0;
	mlx_clear_window(game->mlx_ptr, game->win_ptr);
	while (i < WIDTH)
	{
		init_ray(&game->ray);
		game->ray.camera_x = 2 * i / (double)WIDTH - 1;
		game->ray.ray_dir_x = game->player.dir_x + game->player.plane_x \
		* game->ray.camera_x;
		game->ray.ray_dir_y = game->player.dir_y + game->player.plane_y \
		* game->ray.camera_x;
		game->ray.map_x = game->player.pos_x;
		game->ray.map_y = game->player.pos_y;
		game->ray.delta_dist_x = fabs(1 / game->ray.ray_dir_x);
		game->ray.delta_dist_y = fabs(1 / game->ray.ray_dir_y);
		calc_step(game);
		dda(game);
		perp(game, i);
		i++;
	}
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
	game->fbuffer.ptr, 0, 0);
}
