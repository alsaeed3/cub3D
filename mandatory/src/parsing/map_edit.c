/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_edit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:47:12 by mlumibao          #+#    #+#             */
/*   Updated: 2024/03/23 04:45:03 by alsaeed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	**remove_nl(char **map);

void	edit_map(t_data *game)
{
	game->map.map = remove_nl(game->map.map);
	if (check_enclosed_zero(game->map.map) \
	|| check_enclosed_space(game->map.map))
	{
		free_tmp(game);
		free_array_exit(game->map.map, "Error\n Map not enclosed with walls\n");
	}
}

//Function to trim valid newlines in the map also trims end spaces each row
char	**remove_nl(char **map)
{
	int		i;
	int		j;
	char	**ret;

	i = -1;
	j = 0;
	ret = malloc(sizeof(char *) * (1 + count_line_map(map)));
	if (!ret)
		return (NULL);
	while (map[++i])
	{
		while (map[i] && ft_space_line(map[i]))
			i++;
		while (map[i] &&!ft_space_line(map[i]))
		{
			ret[j] = ft_substr(map[i], 0,
					(ft_strlen(map[i]) - count_end_space(map[i])));
			i++;
			j++;
		}
		ret[j] = NULL;
		break ;
	}
	free_array(map);
	return (ret);
}

int	check_enclosed_zero(char **map)
{
	int	x;
	int	y;

	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] && map[x][y] == '0')
			{
				if (check_left_right_zero(map, x, y)
					|| check_up_down_zero(map, x, y))
				{
					return (1);
				}
			}
			y++;
		}
		x++;
	}
	return (0);
}

int	check_enclosed_space(char **map)
{
	int	x;
	int	y;

	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y] && (map[x][y] == ' ' || map[x][y] == '\t'))
			y++;
		while (map[x][y])
		{
			if ((y < count_line_col(map, y))
				&& (map[x][y] == ' ' || map[x][y] == '\t'))
			{
				if (check_left_right_space(map, x, y)
					|| check_up_down_space(map, x, y))
				{
					return (1);
				}
			}
			y++;
		}
		x++;
	}
	return (0);
}
