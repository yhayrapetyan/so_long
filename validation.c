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
