/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_objects.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdube <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 18:31:55 by sdube             #+#    #+#             */
/*   Updated: 2016/11/03 18:31:58 by sdube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tracer.h"

t_object	new_sphere(t_vec3f pos, t_vec3f o, t_color s, t_f64 rad)
{
	t_object	sp;

	sp = new_object(pos, o, SPHERE);
	sp.radius = rad;
	sp.scolor = s;
	sp.intersect = sphere_intersection;
	sp.normal = sphere_normal;
	return (sp);
}

t_object	new_cone(t_vec3f pos, t_vec3f o, t_color s, t_f64 rad)
{
	t_object	cone;

	cone = new_object(pos, o, CONE);
	cone.radius = rad;
	cone.scolor = s;
	cone.alpha = rad;
	cone.intersect = cone_intersection;
	cone.normal = cone_normal;
	return (cone);
}

t_object	new_plane(t_vec3f pos, t_vec3f size, t_color s)
{
	t_object	plane;

	plane = new_object(pos, size, PLANE);
	plane.size = size;
	plane.scolor = s;
	plane.intersect = plane_intersection;
	plane.normal = plane_normal;
	return (plane);
}

t_object	new_cylinder(t_vec3f pos, t_vec3f o, t_color s, t_f64 rad)
{
	t_object	sp;

	sp = new_object(pos, o, CYLINDER);
	sp.radius = rad;
	sp.scolor = s;
	sp.intersect = cylinder_intersection;
	sp.normal = cylinder_normal;
	return (sp);
}

t_object	new_light(t_vec3f pos, t_color s, t_f64 rad)
{
	t_object	light;

	light = new_sphere(pos, new_uni_color(0), s, rad);
	light.type = LIGHT;
	light.nature = POINT_LIGHT;
	light.ecolor = s;
	return (light);
}
