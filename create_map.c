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

void	create_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	is_surrounded_by_walls(game->draw.map);
	is_map_playable(game->draw.map);
	while (game->draw.map[i])
	{
		j = 0;
		while (game->draw.map[i][j])
		{
			if (game->draw.map[i][j] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->wall.ptr, j * SPRITE_SIZE, i * SPRITE_SIZE);
			else if (game->draw.map[i][j] == '0')
				mlx_put_image_to_window(game->mlx, game->win, game->empty.ptr, j * SPRITE_SIZE, i * SPRITE_SIZE);
			else if (game->draw.map[i][j] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->exit.ptr, j * SPRITE_SIZE, i * SPRITE_SIZE);
			else if (game->draw.map[i][j] == 'P')
					mlx_put_image_to_window(game->mlx, game->win, game->player.ptr, j * SPRITE_SIZE, i * SPRITE_SIZE);
			else if (game->draw.map[i][j] == 'X')
					mlx_put_image_to_window(game->mlx, game->win, game->enemy.ptr, j * SPRITE_SIZE, i * SPRITE_SIZE);
			else if (game->draw.map[i][j] == 'C')
					mlx_put_image_to_window(game->mlx, game->win, game->collectible.ptr, j * SPRITE_SIZE, i * SPRITE_SIZE);
			j++;
		}
		i++;
	}
}
