/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdube <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/24 15:46:07 by sdube             #+#    #+#             */
/*   Updated: 2016/10/24 15:46:09 by sdube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	size_t	size;
	char	*new;

	i = 0;
	if (s && f)
	{
		size = ft_strlen((char *)s);
		new = (char *)malloc(sizeof(char) * (size + 1));
		while (i < size)
		{
			new[i] = f((char)s[i]);
			i++;
		}
		new[i] = '\0';
		return (new);
	}
	return (0);
}
