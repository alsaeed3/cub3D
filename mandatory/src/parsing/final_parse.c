/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlumibao <mlumibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 16:07:59 by mlumibao          #+#    #+#             */
/*   Updated: 2024/03/24 22:07:55 by mlumibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	getplayerpos(t_data *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->map.map[++i])
	{
		j = -1;
		while (game->map.map[i][++j])
		{
			if (game->map.map[i][j] == 'N' || game->map.map[i][j] == 'E' \
			|| game->map.map[i][j] == 'S' || game->map.map[i][j] == 'W')
			{
				game->player.x = i;
				game->player.y = j;
				game->player.facing = game->map.map[i][j];
				game->map.map[i][j] = '0';
				return ;
			}
		}
	}
}

static void	get_direction_2(t_data *game)
{
	if (game->player.facing == 'E')
	{
		game->player.dir_x = 0;
		game->player.dir_y = 1;
		game->player.plane_x = 0.66;
		game->player.plane_y = 0;
	}
	else if (game->player.facing == 'W')
	{
		game->player.dir_x = 0;
		game->player.dir_y = -1;
		game->player.plane_x = -0.66;
		game->player.plane_y = 0;
	}
}

void	get_direction(t_data *game)
{
	if (game->player.facing == 'S')
	{
		game->player.dir_x = 1;
		game->player.dir_y = 0;
		game->player.plane_x = 0;
		game->player.plane_y = -0.66;
	}
	else if (game->player.facing == 'N')
	{
		game->player.dir_x = -1;
		game->player.dir_y = 0;
		game->player.plane_x = 0;
		game->player.plane_y = 0.66;
	}
	else
		get_direction_2(game);
}

void	finaladd(t_data *game)
{
	color(game);
	getplayerpos(game);
	rect_map(game);
	init_player(game);
	init_ray(&game->ray);
	init_mlx(game);
	game->draw_flag = 1;
}
