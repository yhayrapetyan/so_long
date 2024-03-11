int	move(int keycode, t_game *game)
{
	// ft_putnbr_fd(keycode, 1);
	// printf("\n");
	if (keycode == UP_KEY)
	{
		mlx_clear_window(game->mlx, game->win);
		// write(1, "up\n", 3);
		game->img.y -= 32;
		mlx_put_image_to_window(game->mlx, game->win, game->img.ptr, game->img.x, game->img.y);

	}
	else if (keycode == DOWN_KEY)
	{
		mlx_clear_window(game->mlx, game->win);
		// write(1, "down\n", 5);
		game->img.y += 32;
		mlx_put_image_to_window(game->mlx, game->win, game->img.ptr, game->img.x, game->img.y);
	}
	else if (keycode == RIGHT_KEY)
	{
		mlx_clear_window(game->mlx, game->win);
		// write(1, "right\n", 6);
		game->img.x += 32;
		mlx_put_image_to_window(game->mlx, game->win, game->img.ptr, game->img.x, game->img.y);
	}
	else if (keycode == LEFT_KEY)
	{
		mlx_clear_window(game->mlx, game->win);
		// write(1, "left\n", 5);
		game->img.x -= 32;
		mlx_put_image_to_window(game->mlx, game->win, game->img.ptr, game->img.x, game->img.y);
	}
	return (0);
}

void	play_game(void)
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
