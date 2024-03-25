/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wasd_move_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlumibao <mlumibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 04:51:25 by alsaeed           #+#    #+#             */
/*   Updated: 2024/03/25 08:02:55 by mlumibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	move_w(t_data *game)
{
	double	x;
	double	y;

	x = game->player.pos_x + game->player.dir_x * MS;
	y = game->player.pos_y + game->player.dir_y * MS;
	if (check_move(game, x, y))
		game->draw_flag = 1;
}

void	move_s(t_data *game)
{
	double	x;
	double	y;

	x = game->player.pos_x - game->player.dir_x * MS;
	y = game->player.pos_y - game->player.dir_y * MS;
	if (check_move(game, x, y))
		game->draw_flag = 1;
}

void	move_a(t_data *game)
{
	double	x;
	double	y;

	x = game->player.pos_x - game->player.dir_y * MS;
	y = game->player.pos_y + game->player.dir_x * MS;
	if (check_move(game, x, y))
		game->draw_flag = 1;
}

void	move_d(t_data *game)
{
	double	x;
	double	y;

	x = game->player.pos_x + game->player.dir_y * MS;
	y = game->player.pos_y - game->player.dir_x * MS;
	if (check_move(game, x, y))
		game->draw_flag = 1;
}
