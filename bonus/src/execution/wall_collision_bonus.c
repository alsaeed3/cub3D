/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_collision_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlumibao <mlumibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 04:53:24 by alsaeed           #+#    #+#             */
/*   Updated: 2024/03/25 08:02:52 by mlumibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

bool	check_wall(t_data *game, double x, double y)
{
	if (game->map.map[(int)x][(int)y] && game->map.map[(int)x][(int)y] == '0')
		return (true);
	return (false);
}

int	check_move(t_data *game, double x, double y)
{
	int		i;

	i = 0;
	if (check_wall(game, x, game->player.pos_y))
	{
		game->player.pos_x = x;
		i = 1;
	}
	if (check_wall(game, game->player.pos_x, y))
	{
		game->player.pos_y = y;
		i = 1;
	}
	return (i);
}
