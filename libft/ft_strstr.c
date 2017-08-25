/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdube <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/24 15:48:44 by sdube             #+#    #+#             */
/*   Updated: 2016/10/24 15:48:46 by sdube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *foin, const char *aiguille)
{
	int		i;
	int		j;

	i = 0;
	if (aiguille[i] == '\0')
		return ((char *)foin);
	while (foin[i])
	{
		j = 0;
		while (foin[i] == aiguille[j])
		{
			if (aiguille[j + 1] == '\0')
				return ((char *)&foin[i - j]);
			i++;
			if (foin[i] == aiguille[j])
				i--;
			j++;
		}
		i++;
	}
	return (NULL);
}
