/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:19:02 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/03/11 16:19:04 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	*new_sprite(t_game *game, char *path)
{
	t_point	i;

	return (mlx_xpm_file_to_image(game->mlx, path, &i.x, &i.y));
}

static void	init_enemy(t_game *game)
{
	game->enemy.frame1 = new_sprite(game, FRAME1);
	game->enemy.frame2 = new_sprite(game, FRAME2);
	game->enemy.frame3 = new_sprite(game, FRAME3);
	game->enemy.frame4 = new_sprite(game, FRAME4);
}

void	init_images(t_game *game)
{
	game->wall = new_sprite(game, WALL_PATH);
	game->player = new_sprite(game, PLAYER_PATH);
	game->exit = new_sprite(game, EXIT_PATH);
	game->empty = new_sprite(game, EMPTY_PATH);
	game->collectible = new_sprite(game, COLLECTIBLE_PATH);
	init_enemy(game);
}
