/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdube <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 18:39:18 by sdube             #+#    #+#             */
/*   Updated: 2016/11/03 18:39:21 by sdube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

void	ft_swap(t_f64 *a, t_f64 *b)
{
	t_f64	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

t_mat	dup_mat(t_mat *src)
{
	int		i;
	int		j;
	t_mat	mat;

	i = 0;
	mat = new_mat44(1);
	while (i < src->rows)
	{
		j = 0;
		while (j < src->cols)
		{
			mat.mat[i][j] = src->mat[i][j];
			j++;
		}
		i++;
	}
	return (mat);
}

void	cpy_mat(t_mat *dst, t_mat *src)
{
	int	i;
	int	j;

	i = 0;
	while (i < src->rows)
	{
		j = 0;
		while (j < src->cols)
		{
			dst->mat[i][j] = src->mat[i][j];
			j++;
		}
		i++;
	}
}

void	set_row(t_matrix44 m, const int r, const t_f64 *arr)
{
	int	i;

	i = 0;
	while (i < m.cols)
	{
		m.mat[r][i] = arr[i];
		i++;
	}
}

void	set_col(t_matrix44 m, const int c, const t_f64 *arr)
{
	int	i;

	i = 0;
	while (i < m.rows)
	{
		m.mat[i][c] = arr[i];
		i++;
	}
}
