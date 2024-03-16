/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:16:14 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/03/13 14:16:16 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    end_game(t_game *game)
{
    free_split(game->draw.map);
    mlx_destroy_image(game->mlx, game->exit);
    mlx_destroy_image(game->mlx, game->wall);
    mlx_destroy_image(game->mlx, game->empty);
    mlx_destroy_image(game->mlx, game->player);
    mlx_destroy_image(game->mlx, game->collectible);
    mlx_destroy_image(game->mlx, game->enemy.frame1);
    mlx_destroy_image(game->mlx, game->enemy.frame2);
    mlx_destroy_image(game->mlx, game->enemy.frame3);
    mlx_destroy_image(game->mlx, game->enemy.frame4);
    mlx_destroy_window(game->mlx, game->win);
    mlx_destroy_display(game->mlx);
    free(game->mlx);
    exit(0);
}
