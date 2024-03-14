/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 13:36:23 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/03/11 13:36:25 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// IDK why get_screen_size don't work temp solution
void	is_larger_than_screen(t_game *game)
{
	// mlx_get_screen_size(game->mlx, &resolution.x, &resolution.y);
	game->size.x = 0;
	game->size.y = 0;
	game->size.x = ft_strlen(game->draw.map[0]);
	while (game->draw.map[game->size.y])
		game->size.y++;
	if (game->size.x > 60 || game->size.y > 34)
	{
		free_split(game->draw.map);
		ft_error("Invalid map: map size is too big\n");
	}
}

// someone use mlx_destroy_display
void	init_window(t_game *game)
{
	is_larger_than_screen(game);
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, SPRITE_SIZE * game->size.x,
			SPRITE_SIZE * game->size.y, "so_long");
}
