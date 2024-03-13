/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_playable.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 14:41:17 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/03/12 14:41:19 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(char **tab, t_point size, t_point cur, char to_fill)
{
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x)
		return ;
	if (ft_strchr("EXCP", tab[cur.y][cur.x]))
		tab[cur.y][cur.x] = '0';
	if (tab[cur.y][cur.x] != to_fill)
		return ;
	tab[cur.y][cur.x] = 'F';
	flood_fill(tab, size, (t_point){cur.x - 1, cur.y}, to_fill);
	flood_fill(tab, size, (t_point){cur.x + 1, cur.y}, to_fill);
	flood_fill(tab, size, (t_point){cur.x, cur.y - 1}, to_fill);
	flood_fill(tab, size, (t_point){cur.x, cur.y + 1}, to_fill);
}

t_point	find_first_empty_cell(char **str)
{
	t_point	index;

	index.y = 1;
	index.x = 0;
	while (str[index.y])
	{
		while (str[index.y][index.x])
		{
			index.x = 1;
			if (str[index.y][index.x] == '0')
				break ;
			index.x++;
		}
		if (str[index.y][index.x] == '0')
			break ;
		index.y++;
	}
	return (index);
}

char	**copy_map(t_game *game)
{
	char	**cpy;
	int		i;

	cpy = (char **)malloc(sizeof(char *) * (game->size.y + 1));
	if (!cpy)
	{
		free_split(game->draw.map);
		ft_error("Memory allocation failed\n");
	}
	cpy[game->size.y] = NULL;
	i = 0;
	while (i < game->size.y)
	{
		cpy[i] = (char *)malloc(sizeof(char) * (game->size.x + 1));
		if (!cpy[i])
		{
			free_split(game->draw.map);
			free_split(cpy);
			ft_error("Memory allocation failed\n");
		}
		ft_strcpy(cpy[i], game->draw.map[i]);
		i++;
	}
	return (cpy);
}

void	is_map_playable(t_game *game)
{
	t_point	index;
	char	**cpy;


	index = find_first_empty_cell(game->draw.map);
	cpy = copy_map(game);
	flood_fill(cpy, game->size, index, cpy[index.y][index.x]);
	check_is_playable(cpy, game);
	free_split(cpy);
}
