/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdube <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/24 15:39:48 by sdube             #+#    #+#             */
/*   Updated: 2016/10/24 15:39:51 by sdube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int		ft_open(char *file)
{
	int	fd;

	if ((fd = open(file, O_RDONLY)) == -1)
	{
		ft_putendl_fd("Error open", 2);
		perror(file);
		exit(0);
	}
	return (fd);
}
