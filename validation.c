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
