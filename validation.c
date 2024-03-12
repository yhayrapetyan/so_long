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

void	check_is_playable(char **str)
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
				ft_error("Invalid path\n");
			}
			j++;
		}
		i++;
	}
}

void	check_for_double_new_line(char	*str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n' && str[i + 1] == '\n')
			ft_error("Invalid map: double new lines\n");
		i++;
	}
}

void	check_is_rectangle(char **str)
{
	int	i;
	int	temp;

	i = 0;
	temp = ft_strlen(str[i]);
	i++;
	while (str[i])
	{
		if (ft_strlen(str[i]) != temp)
			ft_error("Invalid map: not a rectangle\n");
		i++;
	}
}

void	count(t_counter *counter, char ch)
{
	if (ch == '1')
		counter->wall += 1;
	else if (ch == '0')
		counter->empty += 1;
	else if (ch == 'P')
		counter->player += 1;
	else if (ch == 'C')
		counter->collectible += 1;
	else if (ch == 'E')
		counter->exit += 1;
	else if (ch == 'X')
		counter->enemy += 1;
	else
		ft_error("Invalid map: invalid elements in map\n");
}

void	check_elements(char **str)
{
	t_counter	counter;
	int			i;
	int			j;

	i = 0;
	counter.wall = 0;
	counter.empty = 0;
	counter.player = 0;
	counter.enemy = 0;
	counter.exit = 0;
	counter.collectible = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			count(&counter, str[i][j]);
			j++;
		}
		i++;
	}
	if (counter.player != 1 || counter.exit != 1 || counter.collectible < 1 || \
		counter.empty < 1)
		ft_error("Invalid map: invalid elements count in map\n");
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
void	is_surrounded_by_walls(char **str)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(str[i]);
	if (!is_horizontal_wall(str[i]))
		ft_error("Invalid map: map is not surounded by walls\n");
	while (str[i])
	{
		if (str[i][0] != '1' || str[i][len - 1] != '1')
			ft_error("Invalid map: map is not surounded by walls\n");
		i++;
	}
	if (!is_horizontal_wall(str[i - 1]))
		ft_error("Invalid map: map is not surounded by walls\n");
}
