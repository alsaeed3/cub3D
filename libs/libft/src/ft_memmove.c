/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:18:12 by alsaeed           #+#    #+#             */
/*   Updated: 2024/03/12 01:11:42 by alsaeed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memmove(void *dst, void *src, size_t len)
{
	unsigned char		*d;
	unsigned char		*s;

	if (!dst && !src)
		return (NULL);
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (d > s)
	{
		while (len--)
			d[len] = s[len];
	}
	else
		ft_memcpy(d, s, len);
	return (dst);
}
