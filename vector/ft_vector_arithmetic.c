/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_arithmetic.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdube <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 18:40:20 by sdube             #+#    #+#             */
/*   Updated: 2016/11/03 18:40:23 by sdube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vec3f	sub_vec3f(t_vec3f *v1, t_vec3f *v2)
{
	t_vec3f res;

	res.x = v1->x - v2->x;
	res.y = v1->y - v2->y;
	res.z = v1->z - v2->z;
	return (res);
}

t_vec3f	add_vec3f(t_vec3f *v1, t_vec3f *v2)
{
	t_vec3f	res;

	res.x = v1->x + v2->x;
	res.y = v1->y + v2->y;
	res.z = v1->z + v2->z;
	return (res);
}

double	dot_vec3f(t_vec3f *v1, t_vec3f *v2)
{
	return (v1->x * v2->x + v1->y * v2->y + v1->z * v2->z);
}

t_vec3f	scale_vec3f(t_vec3f *v1, double sk)
{
	t_vec3f	res;

	if (v1 == NULL)
		return (*v1);
	res.x = v1->x * sk;
	res.y = v1->y * sk;
	res.z = v1->z * sk;
	return (res);
}

t_vec3f	cross_vec3f(t_vec3f *a, t_vec3f *b)
{
	t_vec3f	res;

	res = new_vec3f(a->y * b->z - a->z * b->y,
					a->z * b->x - a->x * b->z,
					a->x * b->y - a->y * b->x);
	return (res);
}
