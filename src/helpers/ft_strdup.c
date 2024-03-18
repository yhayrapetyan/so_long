/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:06:11 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/01/10 12:06:12 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strdup(const char *s1)
{
	unsigned int	i;
	char			*ptr;

	i = 0;
	while (s1[i])
		i++;
	ptr = (char *)malloc((i + 1) * sizeof(*s1));
	i = 0;
	if (ptr == NULL)
		return (0);
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
