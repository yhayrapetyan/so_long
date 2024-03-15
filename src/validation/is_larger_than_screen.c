/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_larger_than_screen.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 13:36:23 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/03/11 13:36:25 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// IDK why get_screen_size don't work temp solution
// mlx_get_screen_size(game->mlx, &resolution.x, &resolution.y);
void	is_larger_than_screen(t_game *game)
{
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
