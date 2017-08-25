/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdube <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 18:40:46 by sdube             #+#    #+#             */
/*   Updated: 2016/11/03 18:40:48 by sdube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

void	print_vector(t_vec3f *vec)
{
	printf("%f %f %f\n", vec->x, vec->y, vec->z);
}