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

static int	open_file(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		ft_error("Can't open the file\n");
	return (fd);
}

static int	is_empty(char *str)
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

static char	*ft_smart_trim(char **temp)
{
	char	*trim_temp;

	if (is_empty(*temp))
	{
		trim_temp = *temp;
		*temp = ft_strtrim(*temp, " \t\f\r\v");
		free(trim_temp);
	}
	else
	{
		trim_temp = *temp;
		*temp = ft_strtrim_end(*temp, "\t\f\r\v ");
		free(trim_temp);
	}
	return (*temp);
}

static void	read_file(t_game *game, int fd)
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
		temp = ft_smart_trim(&temp);
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

	game->draw.map = NULL;
	game->step = 0;
	fd = open_file(path);
	read_file(game, fd);
	close(fd);
	if (!game->draw.map[0])
	{
		free_split(game->draw.map);
		ft_error("Invalid map: empty map\n");
	}
	check_is_rectangle(game);
	check_elements(game);
	is_larger_than_screen(game);
	is_surrounded_by_walls(game);
	is_map_playable(game);
}
