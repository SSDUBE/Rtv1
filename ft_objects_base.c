/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_objects_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdube <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 18:32:06 by sdube             #+#    #+#             */
/*   Updated: 2016/11/03 18:32:08 by sdube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tracer.h"

t_object	new_object(t_vec3f pos, t_vec3f o, int t)
{
	t_object	sp;

	sp.pos = pos;
	sp.orientation = o;
	if (t == CYLINDER || t == CONE)
		sp.inverse_matrix = inverse_mat44(new_orientation_mat44(o));
	sp.ecolor = new_uni_color(0);
	sp.radius = 0;
	sp.transparency = 0;
	sp.reflection = FALSE;
	sp.type = -1;
	sp.mirror = FALSE;
	return (sp);
}
