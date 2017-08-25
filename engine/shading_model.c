/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shading_model.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdube <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 18:37:14 by sdube             #+#    #+#             */
/*   Updated: 2016/11/03 18:37:16 by sdube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

t_vec3f	defualt_glossy_shading(t_color *ref, t_color *frac,
	t_f64 feffect, t_object *p)
{
	t_color	tmp;
	t_color	scolor;

	tmp = scale_vec3f(frac, (1 - feffect) * p->transparency);
	scolor = scale_vec3f(ref, feffect);
	scolor = add_vec3f(&scolor, &tmp);
	scolor = mat_vec3f(&scolor, &p->scolor);
	return (add_vec3f(&scolor, &p->ecolor));
}

t_vec3f	phong_shading(t_vlist *vs, t_ray *r, t_params p, t_color e)
{
	t_color	specular;
	t_color	diffuse;
	t_color hit_color;
	t_vec3f	ref;

	diffuse = lambertian_shading(vs->trans, p, vs->v1, e);
	ref = get_reflection_dir(&p.nhit, &vs->v1);
	specular = mat_vec3f(&vs->trans, &e);
	specular = scale_vec3f(&specular, pow(ft_max(0, dot_vec3f(&ref, &r->dir)),
				250));
	hit_color = scale_vec3f(&diffuse, KD * ALBEDO);
	specular = scale_vec3f(&specular, KS);
	hit_color = add_vec3f(&hit_color, &specular);
	return (hit_color);
}

t_vec3f	lambertian_shading(t_vec3f trans, t_params p, t_vec3f ld, t_color e)
{
	t_color	scolor;

	scolor = mat_vec3f(&p.sphere->scolor, &trans);
	scolor = scale_vec3f(&scolor, ft_max(0, dot_vec3f(&p.nhit, &ld)));
	scolor = mat_vec3f(&scolor, &e);
	return (scolor);
}
