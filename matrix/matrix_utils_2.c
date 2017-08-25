/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_utils_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdube <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 18:39:35 by sdube             #+#    #+#             */
/*   Updated: 2016/11/03 18:39:37 by sdube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

void	swap_rows(t_mat mat, int i, int j)
{
	int	k;

	k = 0;
	while (k < 4)
	{
		ft_swap(&mat.mat[i][k], &mat.mat[j][k]);
		k++;
	}
}

void	divide_row(t_mat m, int i, t_f64 temp)
{
	int	j;

	j = 0;
	while (j < 4)
	{
		m.mat[i][j] /= temp;
		j++;
	}
}

void	sub_row(t_mat m, int i, int j, t_f64 temp)
{
	int	k;

	k = 0;
	while (k < 4)
	{
		m.mat[i][k] -= m.mat[j][k] * temp;
		k++;
	}
}

int		get_row(t_mat m, int i)
{
	int	j;

	j = i;
	while (j < 4)
	{
		if (m.mat[j][i] != 0)
			return (j);
		j++;
	}
	return (0);
}
