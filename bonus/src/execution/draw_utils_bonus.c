/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlumibao <mlumibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 17:28:35 by mlumibao          #+#    #+#             */
/*   Updated: 2024/03/25 08:02:25 by mlumibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	init_draw(t_draw *draw)
{
	draw->line_h = 0;
	draw->draw_start = 0;
	draw->draw_end = 0;
	draw->tex_x = 0;
	draw->tex_y = 0;
	draw->wall_x = 0;
	draw->step = 0;
	draw->texpos = 0;
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = NULL;
	if ((x > WIDTH - 1 && x < 0) || (y > HEIGHT - 1 && y < 0))
		return ;
	dst = img->adr + (y * img->len + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}
