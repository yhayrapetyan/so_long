/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_end.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:02:41 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/03/14 16:02:43 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_in_set(char const ch, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == ch)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim_end(char const *s1, char const *set)
{
	char	*ch;
	int		i;
	int		len;

	if (s1 == NULL)
		return (NULL);
	i = 0;
	len = ft_strlen((char *)s1) - 2;
	while (len > 0 && is_in_set(s1[len], set) == 1)
		len--;
	if (len < i)
		return (ft_strdup(""));
	ch = (char *)malloc(sizeof(char) * (len + 2));
	if (ch == NULL)
		return (NULL);
	while (i <= len)
	{
		ch[i] = s1[i];
		i++;
	}
	ch[len + 1] = '\n';
	ch[len + 2] = '\0';
	return (ch);
}
