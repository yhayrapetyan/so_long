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

t_img	new_sprite(t_game *game, char *path)
{
	t_img	img;

	img.ptr = mlx_xpm_file_to_image(game->mlx, path, &img.x, &img.y);
	return (img);
}

void	init_images(t_game *game)
{
	game->wall = new_sprite(game, WALL_PATH);
	game->player = new_sprite(game, PLAYER_PATH);
	game->exit = new_sprite(game, EXIT_PATH);
	game->empty = new_sprite(game, EMPTY_PATH);
	game->collectible = new_sprite(game, COLLECTIBLE_PATH);
	game->enemy = new_sprite(game, ENEMY_PATH);
}
