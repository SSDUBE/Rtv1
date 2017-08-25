/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdube <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 18:31:43 by sdube             #+#    #+#             */
/*   Updated: 2016/11/03 18:31:46 by sdube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tracer.h"

t_color	new_color(double r, double g, double b)
{
	return (new_vec3f(r, g, b));
}

t_color	new_uni_color(double r)
{
	return (new_color(r, r, r));
}
