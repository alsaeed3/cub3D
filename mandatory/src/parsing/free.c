/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlumibao <mlumibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:12:47 by mlumibao          #+#    #+#             */
/*   Updated: 2024/03/24 21:18:49 by mlumibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_array_exit(char **tmp, char *str)
{
	ft_putstr_fd(str, 2);
	free_array(tmp);
	exit (1);
}

void	free_array(char **str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return ;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	if (str)
		free(str);
	str = NULL;
}

void	free_tmp(t_data *game)
{
	if (game->tmp.n_path)
		free(game->tmp.n_path);
	if (game->tmp.e_path)
		free(game->tmp.e_path);
	if (game->tmp.w_path)
		free(game->tmp.w_path);
	if (game->tmp.s_path)
		free(game->tmp.s_path);
	if (game->tmp.f)
		free(game->tmp.f);
	if (game->tmp.c)
		free(game->tmp.c);
}

void	free_all_data(t_data *game)
{
	free_tmp(game);
}
