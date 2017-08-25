/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdube <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/24 15:39:10 by sdube             #+#    #+#             */
/*   Updated: 2016/10/24 15:39:13 by sdube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*dest2;
	const char	*src2;
	char		tmp[n];

	i = 0;
	dest2 = (char *)dest;
	src2 = (const char *)src;
	while (i < n)
	{
		tmp[i] = src2[i];
		i++;
	}
	i = 0;
	while (i < n)
	{
		dest2[i] = tmp[i];
		i++;
	}
	return (dest);
}
