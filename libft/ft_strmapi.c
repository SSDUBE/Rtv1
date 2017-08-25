/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdube <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/24 15:46:23 by sdube             #+#    #+#             */
/*   Updated: 2016/10/24 15:46:25 by sdube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	size;
	char	*new;

	i = 0;
	if (s && f)
	{
		size = ft_strlen((char *)s);
		new = (char *)malloc(sizeof(char) * size);
		while (i < size)
		{
			new[i] = f(i, s[i]);
			i++;
		}
		new[i] = '\0';
		return (new);
	}
	return (0);
}
