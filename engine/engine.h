/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdube <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 18:36:22 by sdube             #+#    #+#             */
/*   Updated: 2016/11/03 18:36:24 by sdube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_H
# define ENGINE_H
# include "tracer.h"
# define MAX_RAY_DEPTH 5
# define KS 0.15
# define KD 0.8
# define ALBEDO 0.4
# define N 250

typedef struct	s_vlist
{
	t_vec3f		refl_color;
	t_vec3f		refl_dir;
	t_vec3f		refr_color;
	t_vec3f		refr_dir;
	t_vec3f		trans;
	t_vec3f		v1;
	t_vec3f		v2;
	t_f64		facingratio;
	t_f64		fresneleffect;
	t_f64		s1;
	t_f64		s2;
	t_f64		s3;
}				t_vlist;

t_vec3f			get_reflection_dir(t_vec3f *nhit, t_vec3f *dir);
t_ray			reflected_ray(t_ray *r, t_vec3f *d, t_vec3f *n, t_vec3f *p);
t_ray			refracted_ray(t_ray *r, t_vec3f *d, t_vec3f *n, t_vec3f *p);
t_params		get_closest_primitive(t_ray *ray, t_objects *sp);
t_color			defualt_glossy_shading(t_color *r, t_color *f,
				t_f64 e, t_object *p);
t_vec3f			phong_shading(t_vlist *l, t_ray *r, t_params p, t_color e);
t_color			lambertian_shading(t_vec3f t, t_params p, t_vec3f l, t_color s);
t_color			compute_ideal_refractions(t_ray *r, t_bool inside, t_params p);
t_f64			get_ior(t_f64 index);
t_f64			get_fresnel(t_object *obj, t_f64 fr);
#endif
