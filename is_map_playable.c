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
		tab[cur.y][cur.x] = 'F';
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
	while (cpy[index.y])
	{
		while (cpy[index.y][index.x])
		{
			index.x = 1;
			if (cpy[index.y][index.x] == '0')
				break ;
			index.x++;
		}
		if (cpy[index.y][index.x] == '0')
			break ;
		index.y++;
	}
}

void	is_map_playable(char **str)
{
	t_point	index;
	t_point	size;
	char	**cpy;
//===========================
	size.x = ft_strlen(str[0]);
	size.y = 1;
	while (str[size.y])
		size.y++;
//===========================
	cpy = (char **)malloc(sizeof(char *) * (size.y + 1));
	if (!cpy)
		ft_error("Memory allocation failed\n");
	cpy[size.y] = NULL;
	int	i = 0;
	int	j;
	while (i < size.y)
	{
		cpy[i] = (char *)malloc(sizeof(char) * (size.x + 1));
		if (!cpy[i])
		{
			free_split(cpy);
			ft_error("Memory allocation failed\n");
		}
		// ft_strlcpy(cpy[i], str[i], size.x);
		j = 0;
		while (str[i][j])
		{
			cpy[i][j] = str[i][j];
			j++;
		}
		cpy[i][j] = 0;
		i++;
	}
	i = 0;
	flood_fill(cpy, size, index, cpy[index.y][index.x]);
	check_is_playable(cpy);
	free_split(cpy);
}
