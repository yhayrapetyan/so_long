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

typedef struct s_img
{
	void	*ptr;
	int		*pixels;
	int		line_size;
	int		mem;
	int		x;
	int		y;
	int		movements;
}	t_img;


typedef struct	s_game {
	void	*mlx;
	void	*win;
	t_img	img;
}				t_game;

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

// int	ft_close( t_vars *vars)
// {
// 	mlx_destroy_window(vars->mlx, vars->win);
// 	return (0);
// }

int	move(int keycode, t_game *game)
{
	if (keycode == 65362)
	{
		mlx_clear_window(game->mlx, game->win);
		// write(1, "up\n", 3);
		game->img.y -= 32;
		mlx_put_image_to_window(game->mlx, game->win, game->img.ptr, game->img.x, game->img.y);
		
	}
	else if (keycode == 65364)
	{
		mlx_clear_window(game->mlx, game->win);
		write(1, "down\n", 5);
		game->img.y += 32;
		mlx_put_image_to_window(game->mlx, game->win, game->img.ptr, game->img.x, game->img.y);
	}
	else if (keycode ==65363)
	{
		mlx_clear_window(game->mlx, game->win);
		write(1, "right\n", 6);
		game->img.x += 32;
		mlx_put_image_to_window(game->mlx, game->win, game->img.ptr, game->img.x, game->img.y);
	}
	else if (keycode == 65361)
	{
		mlx_clear_window(game->mlx, game->win);
		write(1, "left\n", 5);
		game->img.x -= 32;
		mlx_put_image_to_window(game->mlx, game->win, game->img.ptr, game->img.x, game->img.y);
	}
	return (0);
}

void	init_game(void)
{
	t_game	game;
	t_img	img;

	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, 720, 360, "so_long");
	img.ptr = mlx_xpm_file_to_image(game.mlx, "./img/tree.xpm", &img.x, &img.y);
	img.x = 100;
	img.y = 100;
	game.img = img;
	if (img.ptr == NULL)
	{
    	write(1, "Error\n", 6);
    	exit(EXIT_FAILURE);
	}
	mlx_put_image_to_window(game.mlx, game.win, img.ptr, 100, 100);
	mlx_key_hook(game.win, move, &game);
	mlx_loop(game.mlx);
}

int	main(int ac, char **av)
{
	if (ac != 2)
		ft_error("Invalid number of arguments\n");
	if (!is_ber(av[1]))
		ft_error("Invalid argument\n");
	init_game();
	return (0);
}
