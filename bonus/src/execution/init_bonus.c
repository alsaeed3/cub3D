/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 20:06:10 by mlumibao          #+#    #+#             */
/*   Updated: 2024/03/25 22:39:38 by alsaeed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

#ifdef __linux__

void	init_mlx(t_data *game)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		exit_init(game, "Error: Can't initialize mlx\n");
	init_textures(game);
	game->win_ptr = mlx_new_window(game->mlx_ptr, WIDTH, HEIGHT, "cub3D");
	if (!game->win_ptr)
		exit_init(game, "Error: Can't initialize mlx\n");
	game->fbuffer.ptr = mlx_new_image(game->mlx_ptr, WIDTH, HEIGHT);
	if (!game->fbuffer.ptr)
		exit_init(game, "Error: Can't initialize buffer\n");
	game->fbuffer.adr = mlx_get_data_addr(game->fbuffer.ptr, \
	&game->fbuffer.bpp, &game->fbuffer.len, &game->fbuffer.endian);
	if (!game->fbuffer.adr)
		exit_init(game, "Error: Can't initialize buffer\n");
	mlx_mouse_move(game->mlx_ptr, game->win_ptr, WIDTH / 2, HEIGHT / 2);
}

#elif __APPLE__

void	init_mlx(t_data *game)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		exit_init(game, "Error: Can't initialize mlx\n");
	init_textures(game);
	game->win_ptr = mlx_new_window(game->mlx_ptr, WIDTH, HEIGHT, "cub3D");
	if (!game->win_ptr)
		exit_init(game, "Error: Can't initialize mlx\n");
	game->fbuffer.ptr = mlx_new_image(game->mlx_ptr, WIDTH, HEIGHT);
	if (!game->fbuffer.ptr)
		exit_init(game, "Error: Can't initialize buffer\n");
	game->fbuffer.adr = mlx_get_data_addr(game->fbuffer.ptr, \
	&game->fbuffer.bpp, &game->fbuffer.len, &game->fbuffer.endian);
	if (!game->fbuffer.adr)
		exit_init(game, "Error: Can't initialize buffer\n");
	mlx_mouse_move(game->win_ptr, WIDTH / 2, HEIGHT / 2);
}

#endif

void	init_player(t_data *game)
{
	game->player.pos_x = game->player.x + 0.5;
	game->player.pos_y = game->player.y + 0.5;
	game->player.mouse_x = -1;
	game->player.mouse_y = -1;
	get_direction(game);
}

void	init_ray(t_ray *ray)
{
	ray->camera_x = 0;
	ray->ray_dir_x = 0;
	ray->ray_dir_y = 0;
	ray->map_x = 0;
	ray->map_y = 0;
	ray->side_dist_x = 0;
	ray->side_dist_y = 0;
	ray->delta_dist_x = 0;
	ray->delta_dist_y = 0;
	ray->perp_wall_dist = 0;
	ray->step_x = 0;
	ray->step_y = 0;
	ray->hit = 0;
	ray->side = 0;
}

void	destroy_img(t_data *game)
{
	if (game->n_img.ptr)
		mlx_destroy_image(game->mlx_ptr, game->n_img.ptr);
	if (game->s_img.ptr)
		mlx_destroy_image(game->mlx_ptr, game->s_img.ptr);
	if (game->e_img.ptr)
		mlx_destroy_image(game->mlx_ptr, game->e_img.ptr);
	if (game->w_img.ptr)
		mlx_destroy_image(game->mlx_ptr, game->w_img.ptr);
}
