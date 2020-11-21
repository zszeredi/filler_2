/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zszeredi <zszeredi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 16:14:33 by zszeredi          #+#    #+#             */
/*   Updated: 2020/11/21 16:14:38 by zszeredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

static	t_tetra		*push_calc(t_tetra *tet, int index, int i, int j)
{
	tet->push_x = j - tet->cordis[index].x;
	tet->push_n = i - tet->cordis[index].n;
	return (tet);
}

static	int		solver(t_filler *ptr, t_tetra *tet, int i, int j)
{
	int index;

	index = 0;
	while (index < tet->num_stars)
	{
		push_calc(tet, index, i, j);
		if (compare(ptr, tet, tet->push_x, tet->push_n) == 1)
		{
			place(ptr, tet, tet->push_x, tet->push_n);
			return (1);
		}
		index++;
	}
	return (0);
}

int			find_place_down(t_filler *ptr, t_tetra *tet)
{
	int i;
	int j;

	i = ptr->down.n;
	j = ptr->down.x;
	while (i > 0)
	{
		while (j > 0)
		{
			if (ptr->table[i][j] == ptr->me)
			{
				if (solver(ptr, tet, i, j) == 1)
					return (1);
			}
			j--;
		}
		i--;
		j = ptr->columns;
	}
	ptr->coo = coord_copy(ptr->coo, 0, 0);
	ptr->end = 1;
	return (-1);
}

int			find_place_up(t_filler *ptr, t_tetra *tet)
{
	int i;
	int j;

	i = ptr->up.n;
	j = ptr->up.x;
	while (i < ptr->lines)
	{
		while (j < ptr->columns)
		{
			if (ptr->table[i][j] == ptr->me)
			{
				if (solver(ptr, tet, i, j) == 1)
					return (1);
			}
			j++;
		}
		i++;
		j = 0;
	}
	ptr->coo = coord_copy(ptr->coo, 0, 0);
	ptr->end = 1;
	return (-1);
}
