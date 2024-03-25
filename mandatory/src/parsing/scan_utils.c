/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlumibao <mlumibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 15:33:47 by mlumibao          #+#    #+#             */
/*   Updated: 2024/03/24 22:04:58 by mlumibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**scan_map(char **file)
{
	char	**tmp;
	int		i;
	int		valid;

	valid = 0;
	i = 0;
	while (file[i])
	{
		while (ft_space_line(file[i]))
			i++;
		if (!ft_space_line(file[i]))
			valid++;
		i++;
		if (valid == 6 && i <= count_array(file))
		{
			tmp = &file[i];
			return (tmp);
		}
	}
	return (NULL);
}

void	get_store_map(char **file, t_data *game)
{
	char	**ptr_map;
	int		map_len;
	int		i;

	i = -1;
	ptr_map = scan_map(file);
	map_len = count_array(ptr_map);
	if (!ptr_map)
	{
		free_array(file);
		free_tmp(game);
	}
	game->map.map = (char **)malloc(sizeof(char *) * (map_len + 1));
	while (ptr_map[++i])
		game->map.map[i] = ft_strdup(ptr_map[i]);
	game->map.map[i] = NULL;
	free_array(file);
}
