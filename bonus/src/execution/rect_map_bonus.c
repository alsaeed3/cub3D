/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rect_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlumibao <mlumibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:34:55 by mlumibao          #+#    #+#             */
/*   Updated: 2024/03/25 08:02:50 by mlumibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static int	find_row_len(char **map)
{
	int		i;
	int		res;
	int		j;
	char	*ptr;

	i = -1;
	res = 0;
	ptr = NULL;
	while (map[++i])
	{
		j = 0;
		ptr = ft_strrchr(map[i], '1');
		if (ptr)
		{
			while (&map[i][j] != ptr)
				j++;
			if (++j > res)
				res = j;
		}
	}
	return (res);
}

void	fill_map(t_data *game, char **tmp, int len)
{
	int	i;
	int	j;

	i = 0;
	while (game->map.map[i])
	{
		tmp[i] = malloc(sizeof(char) * (len + 1));
		if (!tmp[i])
			return ;
		j = -1;
		while (game->map.map[i][++j])
			tmp[i][j] = game->map.map[i][j];
		while (j < len)
		{
			tmp[i][j] = '1';
			j++;
		}
		tmp[i][j] = '\0';
		i++;
	}
	tmp[i] = NULL;
	free_array(game->map.map);
	game->map.map = tmp;
}

void	tab_space(char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == '\t')
				map[i][j] = ' ';
		}
	}
}

void	rect_map(t_data *game)
{
	char	**tmp;

	tmp = malloc(sizeof (char *) * (count_array(game->map.map) + 1));
	fill_map(game, tmp, find_row_len(game->map.map));
	tab_space(game->map.map);
	game->map.height = count_array(game->map.map);
	game->map.width = find_row_len(game->map.map);
}
