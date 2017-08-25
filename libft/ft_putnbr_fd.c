/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdube <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/24 15:41:29 by sdube             #+#    #+#             */
/*   Updated: 2016/10/24 15:41:31 by sdube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	min;
	char			c;

	min = n;
	if (n < 0)
	{
		write(fd, "-", 1);
		min = -min;
	}
	if (min > 9)
		ft_putnbr_fd((min / 10), fd);
	c = (char)(48 + min % 10);
	write(fd, &c, 1);
}
