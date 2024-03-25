/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elements_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlumibao <mlumibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 20:28:26 by mlumibao          #+#    #+#             */
/*   Updated: 2024/03/25 08:03:44 by mlumibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	check_hex(t_data *game, char **tmp, int type);
void	store_to_rgb(t_data *game, char *str, int type);

void	check_elements(t_data *game)
{
	if (!game->tmp.n_path || !game->tmp.e_path
		|| !game->tmp.w_path || !game->tmp.s_path
		|| !game->tmp.f || !game->tmp.c)
	{
		free_tmp(game);
		ft_putstr_fd("Error\n404 elements not found\n", 2);
		exit (1);
	}
	store_to_rgb(game, game->tmp.f, F);
	store_to_rgb(game, game->tmp.c, C);
	if (game->floor.r == -1 || game->floor.g == -1
		|| game->floor.b == -1 || game->sky.r == -1
		|| game->sky.g == -1 || game->sky.b == -1)
	{
		ft_putstr_fd("Error\nceiling/floor color", 2);
		free_tmp(game);
		exit (1);
	}
}

void	store_to_rgb(t_data *game, char *str, int type)
{
	char	**tmp;

	if (check_comma(str) != 2 || check_valid_char(str) == 1)
	{
		free_tmp(game);
		ft_putstr_fd("Error\n Invalid hex\n", 2);
		exit (1);
	}
	tmp = ft_split_tab(str, ',');
	check_hex(game, tmp, type);
	free_array(tmp);
}

void	check_hex(t_data *game, char **tmp, int type)
{
	if (count_array(tmp) != 3)
		return ;
	if (ft_atol(tmp[0]) == 1 || ft_atol(tmp[1]) == 1 || ft_atol(tmp[2]) == 1)
		return ;
	if (type == F)
	{
		game->floor.r = ft_atoi(tmp[0], NULL);
		game->floor.g = ft_atoi(tmp[1], NULL);
		game->floor.b = ft_atoi(tmp[2], NULL);
	}
	if (type == C)
	{
		game->sky.r = ft_atoi(tmp[0], NULL);
		game->sky.g = ft_atoi(tmp[1], NULL);
		game->sky.b = ft_atoi(tmp[2], NULL);
	}
}
