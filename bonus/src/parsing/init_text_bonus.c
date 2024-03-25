/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_text_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlumibao <mlumibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 20:03:15 by mlumibao          #+#    #+#             */
/*   Updated: 2024/03/25 08:03:51 by mlumibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	xpm_img(t_data *game)
{
	game->n_img.ptr = mlx_xpm_file_to_image(game->mlx_ptr, \
	game->tmp.n_path, &game->n_img.width, &game->n_img.height);
	if (!game->n_img.ptr)
		exit_init(game, "Can't initialize XPM file");
	game->s_img.ptr = mlx_xpm_file_to_image(game->mlx_ptr, \
	game->tmp.s_path, &game->s_img.width, &game->s_img.height);
	if (!game->s_img.ptr)
		exit_init(game, "Can't initialize XPM file");
	game->e_img.ptr = mlx_xpm_file_to_image(game->mlx_ptr, \
	game->tmp.e_path, &game->e_img.width, &game->e_img.height);
	if (!game->e_img.ptr)
		exit_init(game, "Can't initialize XPM file");
	game->w_img.ptr = mlx_xpm_file_to_image(game->mlx_ptr, \
	game->tmp.w_path, &game->w_img.width, &game->w_img.height);
	if (!game->w_img.ptr)
		exit_init(game, "Can't initialize XPM file");
}

void	init_tex_adr(t_data *game)
{
	game->n_img.adr = mlx_get_data_addr(game->n_img.ptr, \
	&game->n_img.bpp, &game->n_img.len, &game->n_img.endian);
	if (!game->n_img.adr)
		return (exit_init(game, "Can't get data address"));
	game->s_img.adr = mlx_get_data_addr(game->s_img.ptr, \
	&game->s_img.bpp, &game->s_img.len, &game->s_img.endian);
	if (!game->s_img.adr)
		return (exit_init(game, "Can't get data address"));
	game->e_img.adr = mlx_get_data_addr(game->e_img.ptr, \
	&game->e_img.bpp, &game->e_img.len, &game->e_img.endian);
	if (!game->e_img.adr)
		return (exit_init(game, "Can't get data address"));
	game->w_img.adr = mlx_get_data_addr(game->w_img.ptr, \
	&game->w_img.bpp, &game->w_img.len, &game->w_img.endian);
	if (!game->w_img.adr)
		return (exit_init(game, "Can't get data address"));
}

void	init_textures(t_data *game)
{
	xpm_img(game);
	init_tex_adr(game);
}

// getting 3 int and storing it in 1 int 
// for hexadecimal colors of floor and ceiling(sky)
uint32_t	conv_color(t_rgb color)
{
	return ((color.r << 16) | (color.g << 8) | color.b);
}

//this function is to convert color and store it ints values inside t_data game
void	color(t_data *game)
{
	game->floorc = conv_color(game->floor);
	game->skyc = conv_color(game->sky);
}
