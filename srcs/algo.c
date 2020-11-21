/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zszeredi <zszeredi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 11:50:22 by zszeredi          #+#    #+#             */
/*   Updated: 2020/11/21 16:07:08 by zszeredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

t_filler		*place(t_filler *ptr, t_tetra *tet, int x, int n)
{
	int i;
	int a;
	int b;

	i = 0;
	while (i < tet->index)
	{
		b = tet->cordis[i].x + x;
		a = tet->cordis[i].n + n;
		if (i == 0)
			ptr->coo = coord_copy(ptr->coo, x - tet->del_col_s,
					n - tet->del_row_s);
		ptr->table[a][b] = ptr->me;
		if (a < 2)
			ptr->wall = 1;
		if (a > ptr->lines - 2)
			ptr->wall = 2;
		i++;
	}
	return (ptr);
}

int				compare(t_filler *ptr, t_tetra *tet, int x, int n)
{
	int i;
	int a;
	int b;
	int counter;

	i = 0;
	counter = 0;
	while (i < tet->index)
	{
		b = tet->cordis[i].x + x;
		a = tet->cordis[i].n + n;
		if (a < 0 || b < 0 || b > ptr->columns - 2 || a > ptr->lines - 1)
			return (-1);
		if ((ptr->table[a][b] == ptr->opp) || counter > 1)
			return (-1);
		else if (ptr->table[a][b] != '.')
			counter++;
		i++;
	}
	if (counter > 1 || counter < 1)
		return (-1);
	return (1);
}

t_tetra			*push_ud(t_filler *ptr, t_tetra *tet, int i)
{
	ext_coords(tet, i);
	if (ptr->q == 4 || ptr->q == 2)
	{
		tet->push_x = ptr->up.x - tet->r.x;
		tet->push_n = ptr->up.n - tet->r.n;
	}
	else if (ptr->q == 1 || ptr->q == 3)
	{
		tet->push_x = ptr->down.x - tet->l.x;
		tet->push_n = ptr->down.n - tet->l.n;
	}
	return (tet);
}

t_filler		*algo(t_filler *ptr, t_tetra *tet)
{
	push_ud(ptr, tet, 0);
	if (compare(ptr, tet, tet->push_x, tet->push_n) < 1)
	{
		if ((ptr->q == 4 && ptr->wall != 1) || ptr->wall == 2)
			find_place_up(ptr, tet);
		else
			find_place_down(ptr, tet);
	}
	else
		place(ptr, tet, tet->push_x, tet->push_n);
	return (ptr);
}
