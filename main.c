/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 14:37:13 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/03/07 14:37:15 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	ft_close( t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

int	main(int ac, char **av)
{
	// void	*mlx;
	// void	*mlx_window;
	// t_data	img;
	t_vars	vars;

	if (ac != 2)
		ft_error("Invalid number of arguments\n");
	if (!is_ber(av[1]))
		ft_error("Invalid argument\n");
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 720, 360, "My Window");
	// img.img = mlx_new_image(mlx, 720, 360);
	// img.bits_per_pixel = 10;
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	// int	i = 0;
	// int color = 0x00FF0000;
	// while (i < 100)
	// {

	// 	my_mlx_pixel_put(&img, 5 + i, 50, color + (i * 50));
	// 	my_mlx_pixel_put(&img, 5, 50 + i, color + (i * 500));
	// 	my_mlx_pixel_put(&img, 5, 50 - i, color + (i * 500));
	// 	i++;
	// }
	// mlx_put_image_to_window(mlx, mlx_window, img.img, 0, 0);
	mlx_hook(vars.win, 3, 1L<<0, ft_close, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
