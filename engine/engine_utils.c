/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdube <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 18:36:33 by sdube             #+#    #+#             */
/*   Updated: 2016/11/03 18:36:36 by sdube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

t_f64	get_ior(t_f64 index)
{
	t_f64	a;
	t_f64	b;

	a = pow(index - 1, 2);
	b = pow(index + 1, 2);
	return (a / b);
}

t_f64	get_fresnel(t_object *obj, t_f64 facingratio)
{
	if (obj->mirror == TRUE)
		return (mix(pow(1 - facingratio, 5), 1, 0.5));
	else if (obj->transparency > 0)
		return (mix(pow(1 - facingratio, 5), 1, get_ior(obj->transparency)));
	else
		return (mix(pow(1 - facingratio, 4), 1, 0.1));
}
