/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_double_new_line.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:19:28 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/03/14 15:19:30 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_for_double_new_line(t_game *game)
{
	int	i;

	i = 0;
	if (!game->draw.line)
	{
		free_split(game->draw.map);
		ft_error("Invalid map: empty map\n");
	}
	while (game->draw.line[i])
	{
		if (game->draw.line[i] == '\n' && game->draw.line[i + 1] == '\n')
		{
			free_split(game->draw.map);
			free(game->draw.line);
			ft_error("Invalid map: double new lines\n");
		}
		i++;
	}
}
