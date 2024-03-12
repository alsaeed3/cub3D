/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaeed <alsaeed@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 12:19:46 by alsaeed           #+#    #+#             */
/*   Updated: 2024/03/12 01:11:40 by alsaeed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/exec.h"

typedef struct s_vars
{
	void	*mlx_ptr;
	void	*mlx_win;
	void	*mlx_img;
	void	*mlx_bnd;
	int		p_y;
	int		p_x;
}	t_vars;

void	move_player(t_vars *vars, int x, int y)
{
	mlx_put_image_to_window(vars->mlx_ptr, vars->mlx_win, vars->mlx_bnd, vars->p_x, vars->p_y);
	vars->p_x = x;
	vars->p_y = y;
	mlx_put_image_to_window(vars->mlx_ptr, vars->mlx_win, vars->mlx_img, x, y);
}

int	keyboard_keys(int key_code, t_vars *vars)
{
	if (key_code == K_ESC)
	{
		mlx_clear_window(vars->mlx_ptr, vars->mlx_win);
		mlx_destroy_window(vars->mlx_ptr, vars->mlx_win);
		exit (0);
	}
	else if (key_code == K_W || key_code == K_A || key_code == K_S || key_code == K_D)
	{
		if (key_code == K_W && vars->p_y > 0)
			move_player(vars, vars->p_x, vars->p_y - 128);
		else if (key_code == K_A && vars->p_x > 0)
			move_player(vars, vars->p_x - 128, vars->p_y);
		else if (key_code == K_S && vars->p_y < 952)
			move_player(vars, vars->p_x, vars->p_y + 128);
		else if (key_code == K_D && vars->p_x < 1792)
			move_player(vars, vars->p_x + 128, vars->p_y);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_vars	vars;
	int		len;

	(void)av;
	(void)ac;
	len = 64;
	// if (ac == 2)
	// {
		vars.mlx_ptr = mlx_init();
		vars.mlx_win = mlx_new_window(vars.mlx_ptr, 1920, 1080, "cub3D");
		vars.mlx_img = mlx_xpm_file_to_image(vars.mlx_ptr, "./textures/86317-sans-area-art-pixel-undertale-png-free-photo_64x64.xpm", &len, &len);
		vars.mlx_bnd = mlx_xpm_file_to_image(vars.mlx_ptr, "./textures/cropped.xpm", &len, &len);
		for (int i = 0; i < 1080; i += 64)
		{
			for (int j = 0; j < 1920; j += 64)
			{
				mlx_put_image_to_window(vars.mlx_ptr, vars.mlx_win, vars.mlx_bnd, j, i);
				if (i == 576 && j == 960)
				{
					vars.p_y = i;
					vars.p_x = j;
					mlx_put_image_to_window(vars.mlx_ptr, vars.mlx_win, vars.mlx_img, j, i);
				}
			}
		}
		mlx_key_hook(vars.mlx_win, keyboard_keys, &vars);
		mlx_loop(vars.mlx_ptr);
	return (0);
	
	// }
	printf("Invalid number of arguments\n");
	return (1);
}