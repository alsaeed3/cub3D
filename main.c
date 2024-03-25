/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlumibao <mlumibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:14:13 by mlumibao          #+#    #+#             */
/*   Updated: 2024/03/25 08:27:06 by mlumibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	game_loop(t_data *game)
{
	if (game->draw_flag == 0)
		return (0);
	calc_ray(game);
	return (1);
}

int	main(int ac, char **av)
{
	t_data		game;

	game = (t_data){0};
	if (ac != 2)
	{
		ft_putstr_fd("Error\n Invalid Syntax ./cub3d 'MAP_PATH'", 2);
		return (0);
	}
	check(av, &game);
	finaladd(&game);
	mlx_loop_hook(game.mlx_ptr, game_loop, &game);
	mlx_hook(game.win_ptr, 2, 1L << 0, key_move, &game);
	mlx_hook(game.win_ptr, 17, 1L << 17, close_game, &game);
	mlx_loop(game.mlx_ptr);
}
