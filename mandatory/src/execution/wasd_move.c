/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wasd_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 04:51:25 by alsaeed           #+#    #+#             */
/*   Updated: 2024/03/23 04:56:50 by alsaeed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
