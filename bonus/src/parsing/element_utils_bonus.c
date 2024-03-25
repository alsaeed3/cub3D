/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlumibao <mlumibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 20:39:22 by mlumibao          #+#    #+#             */
/*   Updated: 2024/03/25 08:03:46 by mlumibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	check_comma(char *str)
{
	int		i;
	int		ret;

	i = -1;
	ret = 0;
	while (str[++i])
	{
		if (str[i] == ',')
			ret++;
	}
	return (ret);
}

int	check_valid_char(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ',' && !ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

long	ft_atol(char *str)
{
	int			i;
	long long	res;

	i = 0;
	res = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	if ((res > 255) || (res < 0))
		return (1);
	return (0);
}
