/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 10:30:13 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/03/11 10:30:15 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	open_file(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		ft_error("Can't open the file\n");
	return (fd);
}

int	is_empty(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_strchr(" \t\r\v\f\n", str[i]))
			return (0);
		i++;
	}
	return (1);
}

// NEED TO FREE draw.map eaven if system_leaks is ok
// in trim maybe more
// in error handling need to check memory leaks
void	read_file(t_game *game, int fd)
{
	char	*temp;
	char	*trim_temp;

	temp = NULL;
	game->draw.line = NULL;
	while (1)
	{
		temp = get_next_line(fd);
		if (!temp)
			break ;
		if (is_empty(temp))
		{
			trim_temp = temp;
			temp = ft_strtrim(temp, " \t\f\r\v");
			free(trim_temp);
		}
		game->draw.line = ft_strjoin(game->draw.line, temp);
		free(temp);
	}
	trim_temp = game->draw.line;
	game->draw.line = ft_strtrim(game->draw.line, "\n");
	free(trim_temp);
	check_for_double_new_line(game);
	game->draw.map = ft_split(game->draw.line, '\n');
	free(game->draw.line);
}


void	init_map(t_game *game, char *path)
{
	int	fd;

	fd = open_file(path);
	read_file(game, fd);
	if (!game->draw.map[0])
		ft_error("Invalid map: empty map\n");
	check_is_rectangle(game);
	check_elements(game);
}
