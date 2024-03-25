/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_code.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:20:48 by alsaeed           #+#    #+#             */
/*   Updated: 2024/03/18 23:06:05 by alsaeed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_CODE_H
# define KEY_CODE_H

# if __APPLE__
#  define K_ESC 53
#  define K_W 13
#  define K_A 0
#  define K_S 1
#  define K_D 2
#  define K_L_ARROW 123
#  define K_R_ARROW 124
# elif __linux__
#  define K_ESC 0xFF1B
#  define K_W 119
#  define K_A 97
#  define K_S 115
#  define K_D 100
#  define K_L_ARROW 65361
#  define K_R_ARROW 65363
# endif

#endif