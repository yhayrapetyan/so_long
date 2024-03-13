/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:16:14 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/03/13 14:16:16 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	movement(int keycode, t_game *game)
{
	if (keycode == UP_KEY)
		move_up(game);
	else if (keycode == DOWN_KEY)
		move_down(game);
	else if (keycode == RIGHT_KEY)
		move_right(game);
	else if (keycode == LEFT_KEY)
		move_left(game);
	else if (keycode == ESC)
	{
		free_split(game->draw.map);
		mlx_destroy_window(game->mlx, game->win);
		system("leaks so_long");
		exit(0);
	}
	printf("step = %d\n", game->step);
	return (0);
}
