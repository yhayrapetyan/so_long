/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:16:14 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/03/13 14:16:16 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_win(t_game *game)
{
	end_game(game);
	return (0);
}

static void	print_steps(t_game *game)
{
	char	*string;
	int		i;

	string = ft_itoa(game->step);
	i = 0;
	while (game->draw.map[0][i])
	{
		pitw(game, 0, i, '1');
		i++;
	}
	mlx_string_put(game->mlx, game->win, STR_X, STR_Y,
		STR_COLOR, "Steps: ");
	mlx_string_put(game->mlx, game->win, STR_X + INTERVAL, STR_Y,
		STR_COLOR, string);
	free(string);
	string = NULL;
}

int	movement(int keycode, t_game *game)
{
	if (keycode == UP_KEY)
		move_to(game, game->position.y - 1, game->position.x, 'U');
	else if (keycode == DOWN_KEY)
		move_to(game, game->position.y + 1, game->position.x, 'D');
	else if (keycode == RIGHT_KEY)
		move_to(game, game->position.y, game->position.x + 1, 'R');
	else if (keycode == LEFT_KEY)
		move_to(game, game->position.y, game->position.x - 1, 'L');
	else if (keycode == ESC)
	{
		end_game(game);
		system("leaks so_long");
	}
	// system("leaks so_long");
	print_steps(game);
	return (0);
}
