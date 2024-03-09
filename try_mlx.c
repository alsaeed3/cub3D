#include "./inc/exec.h"

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		len;
	int		endian;
}	t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->len + x *(data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(int ac, char **av)
{
	void	*mlx_ptr;
	void	*mlx_win;
	t_data	img;

	(void)av;
	(void)ac;
	// if (ac == 2)
	// {
		mlx_ptr = mlx_init();
		mlx_win = mlx_new_window(mlx_ptr, 1920, 1080, "so_long");
		img.img = mlx_new_image(mlx_ptr, 1920, 1080);
		img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.len, &img.endian);
		for (int i = 0; i < 1920; i++)
		{
			my_mlx_pixel_put(&img, i, 5, 0x00FF0000);
		}
		for (int i = 0; i < 1920; i++)
		{
			my_mlx_pixel_put(&img, i, 1075, 0x00FF0000);
		}
		for (int i = 0; i < 1080; i++)
		{
			my_mlx_pixel_put(&img, 5, i, 0x00FF0000);
		}
		for (int i = 0; i < 1080; i++)
		{
			my_mlx_pixel_put(&img, 1915, i, 0x00FF0000);
		}
		mlx_put_image_to_window(mlx_ptr, mlx_win, img.img, 0, 0);
		mlx_loop(mlx_ptr);
	return (0);
	
	// }
	printf("Invalid number of arguments\n");
	return (1);
}