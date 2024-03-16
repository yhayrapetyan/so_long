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
		mlx_put_image_to_window(game->mlx, game->win, game->wall,
			j * SPRITE_SIZE, i * SPRITE_SIZE);
	else if (element == '0')
		mlx_put_image_to_window(game->mlx, game->win, game->empty,
			j * SPRITE_SIZE, i * SPRITE_SIZE);
	else if (element == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->exit,
			j * SPRITE_SIZE, i * SPRITE_SIZE);
	else if (element == 'P')
		mlx_put_image_to_window(game->mlx, game->win, game->player,
			j * SPRITE_SIZE, i * SPRITE_SIZE);
	else if (element == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->collectible,
			j * SPRITE_SIZE, i * SPRITE_SIZE);
}

static void	draw_map(t_game *game)
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
	draw_map(game);
	mlx_string_put(game->mlx, game->win, STR_X, STR_Y,
		STR_COLOR, "Steps: 0");
}
