/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdube <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/24 15:38:29 by sdube             #+#    #+#             */
/*   Updated: 2016/10/24 15:38:33 by sdube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t		i;
	const char	*s3;
	const char	*s4;

	i = 0;
	s3 = s1;
	s4 = s2;
	while (i < n)
	{
		if ((unsigned char)s3[i] != (unsigned char)s4[i])
			return ((unsigned char)s3[i] - (unsigned char)s4[i]);
		i++;
	}
	return (0);
}
