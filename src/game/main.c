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

void	init_game(t_game *game, char *path)
{
	init_map(game, path);
	init_window(game);
	init_images(game);
	create_map(game);
	mlx_loop_hook(game->mlx, enemy_animation, game);
	mlx_hook(game->win, KEY_PRESS, KEY_PRESS_MASK, movement, game);
	mlx_hook(game->win, DESTROY_NOTIFY, NO_EVENT_MASK, close_win, game);
	mlx_loop(game->mlx);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		ft_error("Invalid number of arguments\n");
	if (!is_ber(av[1]))
		ft_error("Invalid argument\n");
	init_game(&game, av[1]);
	return (0);
}
