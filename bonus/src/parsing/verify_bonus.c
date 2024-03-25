/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlumibao <mlumibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 16:34:12 by mlumibao          #+#    #+#             */
/*   Updated: 2024/03/25 08:03:58 by mlumibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	verify_map(t_data *game)
{
	int		i;
	int		map_size;

	map_size = 0;
	i = 0;
	check_map_line(game, &map_size);
	if (check_map_char(game, &i) == 1 || i != 1)
	{
		free_tmp(game);
		free_array_exit(game->map.map,
			"Error\nInvalid character in map or more than 1 player\n");
	}
	edit_map(game);
}

void	check_map_line(t_data *game, int *size)
{
	int	i;
	int	err;

	err = 0;
	i = 0;
	while (game->map.map[i])
	{
		while (game->map.map[i] && ft_space_line(game->map.map[i]))
			i++;
		while (game->map.map[i] && !ft_space_line(game->map.map[i]))
		{
			i++;
			(*size)++;
		}
		while (game->map.map[i] && ft_space_line(game->map.map[i]))
			i++;
		if (game->map.map[i] && !ft_space_line(game->map.map[i]))
			err = 1;
	}
	if (err == 1)
	{
		free_tmp(game);
		free_array_exit(game->map.map, "Error\nNew line in map\n");
	}
}

int	check_map_char(t_data *game, int *charnum)
{
	int		i;
	int		j;

	i = -1;
	while (game->map.map[++i])
	{
		j = -1;
		while (game->map.map[i][++j])
		{
			if (game->map.map[i][j] == 'N' || game->map.map[i][j] == 'E'
				|| game->map.map[i][j] == 'S' || game->map.map[i][j] == 'W')
				(*charnum)++;
			else if (game->map.map[i][j] == '1' || game->map.map[i][j] ==
				'0' ||
					game->map.map[i][j] == ' ' || game->map.map[i][j] == '\n')
				continue ;
			else
				return (1);
		}
	}
	return (0);
}
