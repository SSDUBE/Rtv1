/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdube <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/24 15:45:22 by sdube             #+#    #+#             */
/*   Updated: 2016/10/24 15:45:24 by sdube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size;
	char	*new;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	size = (ft_strlen(s1) + ft_strlen(s2) + 1);
	new = (char *)malloc(sizeof(char) * (size));
	if (new == NULL)
		return (NULL);
	ft_bzero(new, size);
	ft_strcat(new, (char *)s1);
	ft_strcat(new, (char *)s2);
	return (new);
}
