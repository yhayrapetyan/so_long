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

char	**copy_map(char **str, t_point size)
{
	char	**cpy;
	int		i;

	cpy = (char **)malloc(sizeof(char *) * (size.y + 1));
	if (!cpy)
		ft_error("Memory allocation failed\n");
	cpy[size.y] = NULL;
	i = 0;
	while (i < size.y)
	{
		cpy[i] = (char *)malloc(sizeof(char) * (size.x + 1));
		if (!cpy[i])
		{
			free_split(cpy);
			ft_error("Memory allocation failed\n");
		}
		ft_strcpy(cpy[i], str[i]);
		i++;
	}
	return (cpy);
}

void	is_map_playable(char **str)
{
	t_point	index;
	t_point	size;
	char	**cpy;

	size.x = ft_strlen(str[0]);
	size.y = 1;
	while (str[size.y])
		size.y++;

	index = find_first_empty_cell(str);
	cpy = copy_map(str, size);
	flood_fill(cpy, size, index, cpy[index.y][index.x]);
	check_is_playable(cpy);
	free_split(cpy);
}
