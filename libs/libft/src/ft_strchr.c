/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:31:31 by alsaeed           #+#    #+#             */
/*   Updated: 2024/03/12 01:11:40 by alsaeed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strchr(char *s, size_t c)
{
	while (s && *s)
	{
		if (*s == (char)c)
			return (s);
		s++;
	}
	if (!c)
		return (s);
	return (NULL);
}
