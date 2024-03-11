/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 14:37:13 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/03/07 14:37:15 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;


void	init_game(t_game *game, char *path)
{
	init_map(game, path);
	init_window(game);
	init_images(game);
	// create_map(game);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		ft_error("Invalid number of arguments\n");
	if (!is_ber(av[1]))
		ft_error("Invalid argument\n");
	init_game(&game, av[1]);
	// play_game();
	system("leaks so_long");
	return (0);
}
