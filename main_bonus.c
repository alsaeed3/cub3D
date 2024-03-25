/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:14:13 by mlumibao          #+#    #+#             */
/*   Updated: 2024/03/25 22:39:11 by alsaeed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	game_loop(t_data *game)
{
	if (game->draw_flag == 0)
		return (0);
	calc_ray(game);
	return (1);
}
#ifdef __linux__

int	mouse_move(int x, int y, t_data *game)
{
	static int	old_x;

	(void)y;
	if (x == old_x)
		return (0);
	else if (x > 0 || x < (WIDTH >> 1))
	{
		if (x < old_x)
			key_rotate(1, game);
		else if (x > old_x)
			key_rotate(-1, game);
		old_x = x;
	}
	if (x < 20 || x > (WIDTH) - 20)
	{
		mlx_mouse_move(game->mlx_ptr, game->win_ptr, WIDTH >> 1, HEIGHT >> 1);
		old_x = WIDTH >> 1;
	}
	return (0);
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
	mlx_mouse_hide(game.mlx_ptr, game.win_ptr);
	mlx_hook(game.win_ptr, 6, 1L << 6, mouse_move, &game);
	mlx_hook(game.win_ptr, 2, 1L << 0, key_move, &game);
	mlx_hook(game.win_ptr, 17, 1L << 17, close_game, &game);
	mlx_loop(game.mlx_ptr);
}

#elif __APPLE__

int	mouse_move(int x, int y, t_data *game)
{
	static int	old_x;

	(void)y;
	if (x == old_x)
		return (0);
	else if (x > 0 || x < (WIDTH >> 1))
	{
		if (x < old_x)
			key_rotate(1, game);
		else if (x > old_x)
			key_rotate(-1, game);
		old_x = x;
	}
	if (x < 20 || x > (WIDTH) - 20)
	{
		mlx_mouse_move(game->win_ptr, WIDTH >> 1, HEIGHT >> 1);
		old_x = WIDTH >> 1;
	}
	return (0);
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
	mlx_mouse_hide();
	mlx_hook(game.win_ptr, 6, 0, mouse_move, &game);
	mlx_hook(game.win_ptr, 2, 1L << 0, key_move, &game);
	mlx_hook(game.win_ptr, 17, 1L << 17, close_game, &game);
	mlx_loop(game.mlx_ptr);
}

#endif
