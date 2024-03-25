/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlumibao <mlumibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:14:06 by mlumibao          #+#    #+#             */
/*   Updated: 2024/03/25 04:45:32 by mlumibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_space(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

int	ft_space_line(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
	{
		while (ft_space(str[i]) && (str[i] != '\n'))
			i++;
		if (!ft_space(str[i]) && str[i] != '\n')
			return (0);
	}
	return (1);
}

void	init_tmp(t_data *game)
{
	game->tmp.c = NULL;
	game->tmp.f = NULL;
	game->tmp.n_path = NULL;
	game->tmp.e_path = NULL;
	game->tmp.w_path = NULL;
	game->tmp.s_path = NULL;
}

void	init_rgb(t_data *game)
{
	game->floor.r = -1;
	game->floor.g = -1;
	game->floor.b = -1;
	game->sky.r = -1;
	game->sky.g = -1;
	game->sky.b = -1;
}

int	file_line_count(char **av)
{
	int		fd;
	char	*line;
	int		count;

	count = 0;
	fd = open(av[1], O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		count++;
		free(line);
	}
	close(fd);
	return (count);
}
