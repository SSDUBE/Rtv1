/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdube <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/24 15:37:39 by sdube             #+#    #+#             */
/*   Updated: 2016/10/24 15:37:42 by sdube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strrev(char *s)
{
	int		i;
	int		max;
	char	j;

	i = 0;
	max = 0;
	while (s[max])
		max++;
	max--;
	while (i <= max / 2)
	{
		j = s[i];
		s[i] = s[max - i];
		s[max - i] = j;
		i++;
	}
	return (s);
}

char		*ft_itoa(int n)
{
	unsigned int	min;
	int				i;
	char			*new;
	int				save;

	min = n;
	i = 0;
	new = ft_strnew(12);
	if (!new)
		return (NULL);
	save = min;
	if (n < 0)
		min = -min;
	while (min > 9)
	{
		new[i] = ((min % 10) + 48);
		min /= 10;
		i++;
	}
	new[i] = 48 + min;
	if (save < 0)
		new[i + 1] = '-';
	new = ft_strrev(new);
	return (new);
}
