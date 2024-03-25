/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keymap_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlumibao <mlumibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:18:46 by mlumibao          #+#    #+#             */
/*   Updated: 2024/03/25 08:02:43 by mlumibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	key_rotate(int sign, t_data *game)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = 0;
	old_plane_x = 0;
	old_dir_x = game->player.dir_x;
	game->player.dir_x = game->player.dir_x * cos(sign * RS) \
	- game->player.dir_y * sin(sign * RS);
	game->player.dir_y = old_dir_x * sin(sign * RS) + game->player.dir_y \
	* cos(sign * RS);
	old_plane_x = game->player.plane_x;
	game->player.plane_x = game->player.plane_x * cos(sign * RS) \
	- game->player.plane_y * sin(sign * RS);
	game->player.plane_y = old_plane_x * sin(sign * RS) \
	+ game->player.plane_y * cos(sign * RS);
	game->draw_flag = 1;
	return (0);
}

int	key_move(int keycode, t_data *game)
{
	if (keycode == K_ESC)
		close_game(game);
	else if (keycode == K_W)
		move_w(game);
	else if (keycode == K_S)
		move_s(game);
	else if (keycode == K_A)
		move_a(game);
	else if (keycode == K_D)
		move_d(game);
	else if (keycode == K_L_ARROW)
		key_rotate(1, game);
	else if (keycode == K_R_ARROW)
		key_rotate(-1, game);
	return (0);
}
