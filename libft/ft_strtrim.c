/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdube <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/24 15:49:09 by sdube             #+#    #+#             */
/*   Updated: 2016/10/24 15:49:11 by sdube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	char	*new;
	int		start;

	i = 0;
	if (s == NULL)
		return (NULL);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	start = i;
	while (s[i])
		i++;
	i--;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && i >= 0)
		i--;
	(i < start) ? start = i : i;
	new = (char *)malloc(sizeof(char) * (i - start + 2));
	if (new == NULL)
		return (NULL);
	j = -1;
	while (start + ++j <= i)
		new[j] = (char)s[j + start];
	new[j] = '\0';
	return (new);
}
