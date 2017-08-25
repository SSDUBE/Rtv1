/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdube <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 18:32:27 by sdube             #+#    #+#             */
/*   Updated: 2016/11/03 18:32:29 by sdube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tracer.h"

t_stack		*new_stack(int size)
{
	t_stack	*cap;

	cap = (t_stack*)malloc(sizeof(t_stack));
	if (cap == NULL)
		return (NULL);
	cap->store = (t_object*)malloc(sizeof(t_object) * size);
	if (cap->store == NULL)
	{
		free(cap);
		return (NULL);
	}
	cap->top = 0;
	cap->size = size;
	return (cap);
}

t_stack		*push_object(t_stack *sps, t_object *s)
{
	if (sps == NULL)
		return (NULL);
	if (!(sps->top < sps->size))
		return (NULL);
	sps->store[sps->top] = *s;
	sps->top += 1;
	return (sps);
}

t_object	get_object(t_stack *s, int idx)
{
	return (s->store[idx]);
}

void		kill_stack(t_stack **sp)
{
	if (sp != NULL)
	{
		free((*sp)->store);
		free(*sp);
		*sp = NULL;
	}
}
