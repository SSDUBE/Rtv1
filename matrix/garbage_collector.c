/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdube <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 18:38:43 by sdube             #+#    #+#             */
/*   Updated: 2016/11/03 18:38:46 by sdube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

t_matrix	g_garbage[100];
t_i32		g_cnt = 0;

void		garbage_collector(t_matrix44 m)
{
	g_garbage[g_cnt++] = m;
}

void		manual_dispose(t_matrix *m)
{
	int	i;

	i = 0;
	while (i < g_cnt)
	{
		if (g_garbage[i].mat == m->mat)
			g_garbage[i].mat = NULL;
		i++;
	}
	m->mat = NULL;
}

void		dispose_garbage(void)
{
	int	i;

	i = 0;
	while (i < g_cnt)
	{
		if (g_garbage[i].mat != NULL)
		{
			kill_matrix(&g_garbage[i]);
		}
		i++;
	}
}
