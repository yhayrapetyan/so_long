/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_animation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:12:06 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/03/14 15:12:07 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	pitw_enemy(t_game *game, int i, int j, char *element)
{
	if (ft_strcmp(element, "F1") == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->enemy.frame1.ptr,
			j * SPRITE_SIZE, i * SPRITE_SIZE);
	else if (ft_strcmp(element, "F2") == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->enemy.frame2.ptr,
			j * SPRITE_SIZE, i * SPRITE_SIZE);
	else if (ft_strcmp(element, "F3") == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->enemy.frame3.ptr,
			j * SPRITE_SIZE, i * SPRITE_SIZE);
	if (ft_strcmp(element, "F4") == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->enemy.frame4.ptr,
			j * SPRITE_SIZE, i * SPRITE_SIZE);
}

void	draw_enemy(t_game *game, int y, int x)
{
	static int	i;

	if (i < (SPEED / 4))
		pitw_enemy(game, y, x, "F1");
	else if (i < (SPEED / 4) * 2)
		pitw_enemy(game, y, x, "F2");
	else if (i < (SPEED / 4) * 3)
		pitw_enemy(game, y, x, "F3");
	else if (i < (SPEED / 4) * 4)
		pitw_enemy(game, y, x, "F4");
	else
		i = 0;
	i++;
}

int	enemy_animation(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->draw.map[i])
	{
		j = 0;
		while (game->draw.map[i][j])
		{
			if (game->draw.map[i][j] == 'X')
				draw_enemy(game, i, j);
			j++;
		}
		i++;
	}
	return (0);
}
