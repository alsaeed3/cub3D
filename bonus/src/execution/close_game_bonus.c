/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlumibao <mlumibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 09:51:56 by alsaeed           #+#    #+#             */
/*   Updated: 2024/03/25 08:02:20 by mlumibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	put_strerror(char *str)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(str, 2);
	return (0);
}

#ifdef __linux__

int	close_game(t_data *game)
{
	char	**map;

	map = game->map.map;
	mlx_destroy_image(game->mlx_ptr, game->fbuffer.ptr);
	mlx_destroy_image(game->mlx_ptr, game->n_img.ptr);
	mlx_destroy_image(game->mlx_ptr, game->s_img.ptr);
	mlx_destroy_image(game->mlx_ptr, game->e_img.ptr);
	mlx_destroy_image(game->mlx_ptr, game->w_img.ptr);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	free_tmp(game);
	free_array(map);
	exit (0);
}

#elif __APPLE__

int	close_game(t_data *game)
{
	if (game->fbuffer.ptr)
		mlx_destroy_image(game->mlx_ptr, game->fbuffer.ptr);
	destroy_img(game);
	if (game->win_ptr)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	free(game->mlx_ptr);
	free_tmp(game);
	free_array(game->map.map);
	exit (0);
}
#endif

#ifdef __linux__

void	exit_init(t_data *game, char *str)
{
	if (game->map.map && game->fbuffer.ptr)
		mlx_destroy_image(game->mlx_ptr, game->fbuffer.ptr);
	if (game->win_ptr)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	if (game->map.map)
		free_array(game->map.map);
	if (game->mlx_ptr)
	{
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
	}
	free_tmp(game);
	if (str)
		put_strerror(str);
	exit (1);
}

#elif __APPLE__

void	exit_init(t_data *game, char *str)
{
	if (game->mlx_ptr && game->map.map && game->fbuffer.ptr)
		mlx_destroy_image(game->mlx_ptr, game->fbuffer.ptr);
	if (game->win_ptr)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	if (game->map.map)
		free_array(game->map.map);
	if (game->mlx_ptr)
		free(game->mlx_ptr);
	free_tmp(game);
	if (str)
		put_strerror(str);
	exit (1);
}
#endif
