/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdube <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 18:36:11 by sdube             #+#    #+#             */
/*   Updated: 2016/11/03 18:36:14 by sdube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

static inline t_color	recursive_tracer(t_params p, t_ray *ray,
		t_objects *sp)
{
	t_vlist	vars;
	t_f64	inside;
	t_ray	rx;

	if ((inside = dot_vec3f(&ray->dir, &p.nhit) > 0))
		p.nhit = scale_vec3f(&p.nhit, -1);
	vars.facingratio = -dot_vec3f(&ray->dir, &p.nhit);
	vars.fresneleffect = get_fresnel(p.sphere, vars.facingratio);
	vars.refl_dir = get_reflection_dir(&p.nhit, &ray->dir);
	rx = reflected_ray(ray, &vars.refl_dir, &p.nhit, &p.phit);
	vars.refl_color = trace_ray(&rx, sp, ++p.depth);
	vars.refr_color = new_uni_color(0);
	if (p.sphere->transparency > 0)
	{
		vars.refr_dir = compute_ideal_refractions(ray, inside, p);
		rx = refracted_ray(ray, &vars.refr_dir, &p.nhit, &p.phit);
		vars.refr_color = vars.refr_dir.x != -1234 ?
			trace_ray(&rx, sp, ++p.depth) : new_uni_color(0);
	}
	return (defualt_glossy_shading(&vars.refl_color,
				&vars.refr_color, vars.fresneleffect, p.sphere));
}

static inline t_color	sharp_shadows(t_params p,
				t_ray *r, t_objects *s, t_vec3f ld)
{
	t_f64	t0;
	int		i;
	t_ray	sray;

	i = 0;
	while (i < s->top)
	{
		if (s->store[i].type != LIGHT)
		{
			sray = dup_ray(r);
			sray.origin = scale_vec3f(&p.nhit, BIAS);
			sray.origin = add_vec3f(&sray.origin, &p.phit);
			sray.dir = ld;
			if (s->store[i].intersect(&sray, &s->store[i], &t0, &t0))
				return (new_uni_color(0));
		}
		i++;
	}
	return (new_uni_color(1));
}

static inline t_color	soft_shadows(t_params p, t_ray *r, t_objects *s, int j)
{
	int		x;
	int		y;
	t_vlist	vars;
	t_vec3f	lp;

	vars.trans = new_uni_color(0);
	x = -1;
	while (++x < 5 && !(y = 0))
	{
		while (y < 5)
		{
			vars.v2 = new_vec3f(x, 0, y);
			lp = add_vec3f(&s->store[j].pos, &vars.v2);
			if (sharp_shadows(p, r, s,
				normalize_vec3f(sub_vec3f(&lp, &p.phit))).x != 0)
			{
				vars.v1 = new_vec3f(1 / 25., 1 / 25., 1 / 25.);
				vars.trans = add_vec3f(&vars.trans, &vars.v1);
			}
			++y;
		}
	}
	return (vars.trans);
}

t_vec3f					single_tracer(t_params p, t_ray *ray, t_objects *sp)
{
	int		i;
	t_vlist	vs;
	t_vec3f	tmp;
	t_color	scolor;

	i = -1;
	if (dot_vec3f(&ray->dir, &p.nhit) > 0)
		p.nhit = scale_vec3f(&p.nhit, -1);
	scolor = new_uni_color(0);
	while (++i < sp->top)
	{
		if (sp->store[i].type == LIGHT)
		{
			vs.v1 = normalize_vec3f(sub_vec3f(&sp->store[i].pos, &p.phit));
			if (sp->store[i].nature == AREA_LIGHT)
				vs.trans = soft_shadows(p, ray, sp, i);
			else
				vs.trans = sharp_shadows(p, ray, sp, vs.v1);
			tmp = phong_shading(&vs, ray, p, sp->store[i].ecolor);
			scolor = add_vec3f(&scolor, &tmp);
		}
	}
	return (add_vec3f(&scolor, &p.sphere->ecolor));
}

t_vec3f					trace_ray(t_ray *ray, t_objects *sp, int depth)
{
	t_params	param;

	param = get_closest_primitive(ray, sp);
	param.depth = depth;
	if (param.sphere == NULL)
		return (new_uni_color(4));
	param.phit = scale_vec3f(&ray->dir, param.tnear);
	param.phit = add_vec3f(&ray->origin, &param.phit);
	param.nhit = param.sphere->normal(&param.phit, &param.sphere->pos,
			param.sphere->inverse_matrix);
	param.ray = ray;
	if ((param.sphere)->reflection > 0 && depth < MAX_RAY_DEPTH)
		return (recursive_tracer(param, ray, sp));
	return (single_tracer(param, ray, sp));
}
