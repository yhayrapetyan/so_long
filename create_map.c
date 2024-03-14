/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 17:07:22 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/03/11 17:07:23 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	pitw(t_game *game, int i, int j, char element)
{
	if (element == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->wall.ptr,
			j * SPRITE_SIZE, i * SPRITE_SIZE);
	else if (element == '0')
		mlx_put_image_to_window(game->mlx, game->win, game->empty.ptr,
			j * SPRITE_SIZE, i * SPRITE_SIZE);
	else if (element == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->exit.ptr,
			j * SPRITE_SIZE, i * SPRITE_SIZE);
	else if (element == 'P')
		mlx_put_image_to_window(game->mlx, game->win, game->player.ptr,
			j * SPRITE_SIZE, i * SPRITE_SIZE);
	else if (element == 'X')
		mlx_put_image_to_window(game->mlx, game->win, game->enemy.ptr,
			j * SPRITE_SIZE, i * SPRITE_SIZE);
	else if (element == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->collectible.ptr,
			j * SPRITE_SIZE, i * SPRITE_SIZE);
}

void	draw_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->draw.map[i])
	{
		j = 0;
		while (game->draw.map[i][j])
		{
			if (game->draw.map[i][j] == '1')
				pitw(game, i, j, game->draw.map[i][j]);
			else if (game->draw.map[i][j] == '0')
				pitw(game, i, j, game->draw.map[i][j]);
			else if (game->draw.map[i][j] == 'E')
				pitw(game, i, j, game->draw.map[i][j]);
			else if (game->draw.map[i][j] == 'P')
				pitw(game, i, j, game->draw.map[i][j]);
			else if (game->draw.map[i][j] == 'X')
				pitw(game, i, j, game->draw.map[i][j]);
			else if (game->draw.map[i][j] == 'C')
				pitw(game, i, j, game->draw.map[i][j]);
			j++;
		}
		i++;
	}
}

void	create_map(t_game *game)
{
	is_surrounded_by_walls(game);
	is_map_playable(game);
	draw_map(game);
	mlx_string_put(game->mlx, game->win, 0, 0, 0xFFFFFF, "Steps: 0");
}
