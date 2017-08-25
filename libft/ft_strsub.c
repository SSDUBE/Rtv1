/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdube <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/24 15:48:54 by sdube             #+#    #+#             */
/*   Updated: 2016/10/24 15:48:57 by sdube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*new;

	i = 0;
	if (s)
	{
		new = (char *)malloc(sizeof(char) * (len + 1));
		if (new == NULL)
			return (NULL);
		ft_bzero(new, len);
		while (i < len && s[start])
		{
			new[i] = (char)s[start];
			start++;
			i++;
		}
		new[i] = '\0';
		return (new);
	}
	return (NULL);
}
