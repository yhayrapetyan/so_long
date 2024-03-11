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
t_resolution	*is_larger_than_screen(t_game *game)
{
	t_resolution	*resolution;
	int				i;

	resolution = (t_resolution *)malloc(sizeof(t_resolution *));
	// mlx_get_screen_size(game->mlx, &resolution.x, &resolution.y);
	resolution->x = 0;
	resolution->y = 0;
	i = 0;
	resolution->x = ft_strlen(game->draw.map[i]);
	while (game->draw.map[i])
	{
		resolution->y += 1;
		i++;
	}
	if (resolution->x > 60 || resolution->y > 33)
	{
		free(resolution);
		return (NULL);
	}
	return (resolution);
}

// someone use mlx_destroy_display
void	init_window(t_game *game)
{
	t_resolution	*res;

	res = is_larger_than_screen(game);
	game->mlx = mlx_init();
	if (res == NULL)
	{
		free_split(game->draw.map);
		ft_error("Invalid map: map size is too big\n");
	}
	game->win = mlx_new_window(game->mlx, SPRITE_SIZE * res->x,
			SPRITE_SIZE * res->y, "so_long");
	free(res);
	return ;
}
