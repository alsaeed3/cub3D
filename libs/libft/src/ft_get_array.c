/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:24:03 by alsaeed           #+#    #+#             */
/*   Updated: 2024/03/12 01:11:40 by alsaeed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	**ft_get_array(int ac, char **av)
{
	char	*str;
	char	**array;

	str = NULL;
	array = NULL;
	str = ft_strjoin_sp(ac, av);
	array = ft_split(str, ' ');
	free_set_null((void **)&str);
	if (ft_array_size(array) <= 1)
	{
		ft_free_array(&array);
		exit (0);
	}
	return (array);
}
