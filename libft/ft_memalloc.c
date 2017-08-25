/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdube <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/24 15:37:51 by sdube             #+#    #+#             */
/*   Updated: 2016/10/24 15:37:53 by sdube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*memzone;

	memzone = (char *)malloc(sizeof(char) * size);
	if (memzone == NULL)
		return (NULL);
	ft_bzero(memzone, size);
	return (memzone);
}
