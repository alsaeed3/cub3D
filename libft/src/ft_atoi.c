/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:34:50 by alsaeed           #+#    #+#             */
/*   Updated: 2024/03/12 01:11:40 by alsaeed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_atoi(char *s, int *error)
{
	int			i;
	long int	integer;
	int			sign;

	i = 0;
	integer = 0;
	sign = 1;
	while (s[i] == ' ')
		i++;
	if (s[i] == '-')
		sign *= -1;
	if (s[i] == '-' || s[i] == '+')
		i++;
	while ((s[i] >= '0' && s[i] <= '9') || s[i] == '+' || s[i] == '-' )
	{
		integer = integer * 10 + s[i] - 48;
		if (((integer * sign) > 2147483647) || ((integer * sign) < -2147483648))
			*error = -1;
		i++;
	}
	return (integer * sign);
}
