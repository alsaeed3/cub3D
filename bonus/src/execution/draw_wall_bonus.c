/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlumibao <mlumibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 04:35:24 by alsaeed           #+#    #+#             */
/*   Updated: 2024/03/25 08:02:30 by mlumibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	get_wall_direction(t_data *game)
{
	if (game->ray.side == 0)
	{
		if (game->ray.ray_dir_x < 0)
			return (1);
		return (2);
	}
	else
	{
		if (game->ray.ray_dir_y > 0)
			return (3);
		else
			return (4);
	}
}

int	text_color(t_img img, int x, int y)
{
	char	*index;
	int		color;

	index = img.adr + (y * img.len + x * (img.bpp / 8));
	color = *(unsigned int *)(index);
	return (color);
}

void	draw_tex(t_data *game, t_draw *draw, int i, t_img img)
{
	int	y;
	int	color;

	if (game->ray.side == 0)
		draw->texpos = game->player.pos_y + game->ray.perp_wall_dist \
		* game->ray.ray_dir_y;
	else
		draw->texpos = game->player.pos_x + game->ray.perp_wall_dist \
		* game->ray.ray_dir_x;
	draw->texpos -= floor(draw->texpos);
	draw->tex_x = (int)(draw->texpos * img.height);
	draw->step = 1.0 * img.height / draw->line_h;
	draw->texpos = (draw->draw_start - HEIGHT / 2 + draw->line_h / 2) \
	* draw->step;
	y = draw->draw_start;
	while (y < draw->draw_end)
	{
		draw->tex_y = (int)draw->texpos & (img.height - 1);
		draw->texpos += draw->step;
		color = text_color(img, draw->tex_x, draw->tex_y);
		my_mlx_pixel_put(&game->fbuffer, i, y, color);
		y++;
	}
}

void	draw_wall(t_data *game, t_draw *draw, int i)
{
	int	wall;

	wall = get_wall_direction(game);
	if (wall == 1)
		draw_tex(game, draw, i, game->s_img);
	else if (wall == 2)
		draw_tex(game, draw, i, game->n_img);
	else if (wall == 3)
		draw_tex(game, draw, i, game->w_img);
	else
		draw_tex(game, draw, i, game->e_img);
}
