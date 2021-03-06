/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdube <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 18:40:07 by sdube             #+#    #+#             */
/*   Updated: 2016/11/03 18:40:10 by sdube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vec3f	new_vec3f(double x, double y, double z)
{
	t_vec3f	p;

	p.x = x;
	p.y = y;
	p.z = z;
	return (p);
}

t_vec3f	cpy_vec3f(t_vec3f *dest, t_vec3f *src)
{
	dest->x = src->x;
	dest->y = src->y;
	dest->z = src->z;
	return (*dest);
}

t_vec3f	dup_vec3f(t_vec3f *src)
{
	t_vec3f	dest;

	dest.x = src->x;
	dest.y = src->y;
	dest.z = src->z;
	return (dest);
}
