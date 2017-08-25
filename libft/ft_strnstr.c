/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdube <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/24 15:48:03 by sdube             #+#    #+#             */
/*   Updated: 2016/10/24 15:48:05 by sdube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *foin, const char *aiguille, size_t n)
{
	size_t		i;
	size_t		j;

	i = 0;
	if (aiguille[i] == '\0')
		return ((char *)foin);
	while (foin[i])
	{
		j = 0;
		while (foin[i] == aiguille[j] && (i < n) && foin[i] != '\0')
		{
			if (aiguille[j + 1] == '\0')
				return ((char *)&foin[i - j]);
			i++;
			if (foin[i] == aiguille[j])
				i--;
			j++;
		}
		if (foin[i] != '\0')
			i++;
	}
	return (NULL);
}
