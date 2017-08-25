/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdube <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/24 15:41:11 by sdube             #+#    #+#             */
/*   Updated: 2016/10/24 15:41:13 by sdube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	unsigned int	min;
	char			c;

	min = n;
	if (n < 0)
	{
		write(1, "-", 1);
		min = -min;
	}
	if (min > 9)
		ft_putnbr(min / 10);
	c = (char)(48 + min % 10);
	write(1, &c, 1);
}