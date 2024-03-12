/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_undec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 19:11:44 by alsaeed           #+#    #+#             */
/*   Updated: 2024/03/12 01:11:40 by alsaeed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	print_undec(unsigned int n)
{
	int	len;

	len = 0;
	if (n > 9)
		len += print_undec(n / 10);
	len += ft_putchar((n % 10) + '0');
	return (len);
}
