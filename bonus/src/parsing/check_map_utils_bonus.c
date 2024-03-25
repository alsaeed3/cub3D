/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlumibao <mlumibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 22:49:29 by mlumibao          #+#    #+#             */
/*   Updated: 2024/03/25 08:03:45 by mlumibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	check_left_right_zero(char **map, int x, int y)
{
	int		i;
	int		rowsize;

	rowsize = ft_strlen(map[x]);
	i = y;
	while (i >= 0 && map[x][i])
	{
		if (map[x][i] && map[x][i] == '1')
			break ;
		else if (map[x][i] && ft_space(map[x][i]))
			return (1);
		i--;
	}
	i = y;
	while (i < rowsize && map[x][i])
	{
		if (map[x][i] && map[x][i] == '1')
			break ;
		else if ((map[x][i] && ft_space(map[x][i]))
			|| ((i == rowsize - 1) && map[x][i] != '1'))
			return (1);
		i++;
	}
	return (0);
}

int	check_up_down_zero(char **map, int x, int y)
{
	int		i;
	int		colsize;

	colsize = count_line_col(map, y);
	i = x;
	while (i >= 0 && map[i][y])
	{
		if (map[i][y] && map[i][y] == '1')
			break ;
		else if ((map[i][y] && ft_space(map[i][y]))
			|| ((i == 0) && map[i][y] != '1'))
			return (1);
		i--;
	}
	i = x;
	while (i < colsize && map[i][y])
	{
		if (map[i][y] && map[i][y] == '1')
			break ;
		else if ((map[i][y] && ft_space(map[i][y]))
			|| ((i == colsize - 1) && map[i][y] != '1'))
			return (1);
		i++;
	}
	return (0);
}

int	check_left_right_space(char **map, int x, int y)
{
	int		i;
	int		rowsize;

	rowsize = ft_strlen(map[x]);
	i = y;
	while (i >= 0 && map[x][i])
	{
		if (map[x][i] && map[x][i] == '1')
			break ;
		else if ((map[x][i] && ft_valid_char(map[x][i]))
			|| ((i == 0) && map[x][i] != '1'))
			return (1);
		i--;
	}
	i = y;
	while (i < rowsize && map[x][i])
	{
		if (map[x][i] && map[x][i] == '1')
			break ;
		else if ((map[x][i] && ft_valid_char(map[x][i]))
			|| ((i == rowsize - 1) && map[x][i] != '1'))
			return (1);
		i++;
	}
	return (0);
}

int	check_up_down_space(char **map, int x, int y)
{
	int		i;
	int		colsize;

	colsize = count_line_col(map, y);
	i = x;
	while (i >= 0 && map[i][y])
	{
		if (map[i][y] && map[i][y] == '1')
			break ;
		else if (map[i][y] && ft_valid_char(map[i][y]))
			return (1);
		i--;
	}
	i = x;
	while (i < colsize && map[i][y])
	{
		if (map[i][y] && map[i][y] == '1')
			break ;
		else if ((map[i][y] && ft_valid_char(map[i][y]))
			|| ((i == colsize - 1) && map[i][y] != '1'))
			return (1);
		i++;
	}
	return (0);
}

int	ft_valid_char(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W' || c == '0')
		return (1);
	return (0);
}
