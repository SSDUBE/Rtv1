/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdube <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/24 15:45:42 by sdube             #+#    #+#             */
/*   Updated: 2016/10/24 15:45:44 by sdube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t count)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!count)
		return (ft_strlen(src));
	if (!dest)
		return (0);
	while (dest[i] && i < count)
		i++;
	while (i + j < count - 1 && src[j])
	{
		dest[i + j] = src[j];
		j++;
	}
	if (i + j != count)
		dest[i + j] = '\0';
	while (src[j])
		j++;
	return (i + j);
}
