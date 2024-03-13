/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 14:50:23 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/03/07 14:50:34 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_ber(char *str)
{
	if (!str)
		return (0);
	if (ft_strlen(str) < 5)
		return (0);
	if (ft_strcmp(str + (ft_strlen(str) - 4), ".ber") != 0)
		return (0);
	return (1);
}

void	check_is_playable(char **str, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (!ft_strchr("1FX", str[i][j]))
			{
				free_split(str);
				free_split(game->draw.map);
				ft_error("Invalid path\n");
			}
			j++;
		}
		i++;
	}
}

void	check_for_double_new_line(t_game *game)
{
	int	i;

	i = 0;
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

void	check_is_rectangle(t_game *game)
{
	int	i;
	int	temp;

	i = 0;
	temp = ft_strlen(game->draw.map[i]);
	i++;
	while (game->draw.map[i])
	{
		if (ft_strlen(game->draw.map[i]) != temp)
		{
			free_split(game->draw.map);
			ft_error("Invalid map: not a rectangle\n");
		}
		i++;
	}
}

void	count(t_game *game, char ch, int y, int x)
{
	if (ch == '1')
		game->counter.wall += 1;
	else if (ch == '0')
		game->counter.empty += 1;
	else if (ch == 'P')
	{
		game->counter.player += 1;
		game->position.x = x;
		game->position.y = y;
	}
	else if (ch == 'C')
		game->counter.collectible += 1;
	else if (ch == 'E')
		game->counter.exit += 1;
	else if (ch == 'X')
		game->counter.enemy += 1;
	else
	{
		free_split(game->draw.map);
		ft_error("Invalid map: invalid elements in map\n");
	}
}

t_counter	init_counter(void)
{
	t_counter	counter;

	counter.wall = 0;
	counter.empty = 0;
	counter.player = 0;
	counter.enemy = 0;
	counter.exit = 0;
	counter.collectible = 0;
	return (counter);
}

void	check_elements(t_game *game)
{
	int			i;
	int			j;

	i = 0;
	game->counter = init_counter();
	while (game->draw.map[i])
	{
		j = 0;
		while (game->draw.map[i][j])
		{
			count(game, game->draw.map[i][j], i, j);
			j++;
		}
		i++;
	}
	if (game->counter.player != 1 || game->counter.exit != 1 || \
		game->counter.collectible < 1 || game->counter.empty < 1)
	{
		free_split(game->draw.map);
		ft_error("Invalid map: invalid elements count in map\n");
	}
}
int	is_horizontal_wall(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

//need to check for NULL maybe
void	is_surrounded_by_walls(t_game *game)
{
	int	i;

	i = 0;
	if (!is_horizontal_wall(game->draw.map[i]))
	{
		free_split(game->draw.map);
		ft_error("Invalid map: map is not surounded by walls\n");
	}
	while (game->draw.map[i])
	{
		if (game->draw.map[i][0] != '1' || \
			game->draw.map[i][game->size.x - 1] != '1')
		{
			free_split(game->draw.map);
			ft_error("Invalid map: map is not surounded by walls\n");
		}
		i++;
	}
	if (!is_horizontal_wall(game->draw.map[i - 1]))
	{
		free_split(game->draw.map);
		ft_error("Invalid map: map is not surounded by walls\n");
	}
}
