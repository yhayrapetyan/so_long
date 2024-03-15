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
    mlx_destroy_image(game->mlx, game->exit.ptr);
    mlx_destroy_image(game->mlx, game->wall.ptr);
    mlx_destroy_image(game->mlx, game->empty.ptr);
    mlx_destroy_image(game->mlx, game->player.ptr);
    mlx_destroy_image(game->mlx, game->collectible.ptr);
    mlx_destroy_image(game->mlx, game->enemy.frame1.ptr);
    mlx_destroy_image(game->mlx, game->enemy.frame2.ptr);
    mlx_destroy_image(game->mlx, game->enemy.frame3.ptr);
    mlx_destroy_image(game->mlx, game->enemy.frame4.ptr);
    mlx_destroy_window(game->mlx, game->win);
    mlx_destroy_display(game->mlx);
    free(game->mlx);
    exit(0);
}