/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_nonl.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 10:55:54 by alsaeed           #+#    #+#             */
/*   Updated: 2024/03/18 03:03:46 by alsaeed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strdup_nonl(const char *s1)
{
	char	*dup;
	int		count;

	count = 0;
	dup = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!dup)
		return (NULL);
	while (*s1 && *s1 != '\n')
	{
		*dup++ = *s1++;
		count++;
	}
	*dup = '\0';
	dup = dup - count;
	s1 = s1 - count;
	return (dup);
}
