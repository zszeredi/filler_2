/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zszeredi <zszeredi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 11:27:08 by zszeredi          #+#    #+#             */
/*   Updated: 2020/11/21 16:31:58 by zszeredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

void		*delete_rest(void *ptr, char **str, int n)
{
	ft_delete_double_array(str, n);
	free(ptr);
	return (NULL);
}

t_coords	coord_copy(t_coords coo, int j, int i)
{
	coo.x = j;
	coo.n = i;
	return (coo);
}

t_tetra		*ext_coords(t_tetra *tet, int c)
{
	int i;

	i = 0;
	while (i < tet->index)
	{
		if ((tet->cordis[i].x < tet->l.x && c == 0) ||
				(tet->cordis[i].x <= tet->l.x && c == 1))
			tet->l = coord_copy(tet->l, tet->cordis[i].x, tet->cordis[i].n);
		if ((tet->cordis[i].x >= tet->r.x && c == 0) ||
				(tet->cordis[i].x >= tet->l.x && c == 1))
			tet->r = coord_copy(tet->r, tet->cordis[i].x, tet->cordis[i].n);
		i++;
	}
	return (tet);
}

int			quadrant(t_filler *ptr)
{
	int ud;
	int lr;

	if (ptr->columns / 2 > ptr->me_s.x)
		lr = 1;
	else
		lr = 2;
	if (ptr->lines / 2 > ptr->me_s.n)
		ud = 1;
	else
		ud = 2;
	if (lr == 1 && ud == 1)
		ptr->q = 1;
	if (lr == 2 && ud == 1)
		ptr->q = 2;
	if (lr == 1 && ud == 2)
		ptr->q = 3;
	if (lr == 2 && ud == 2)
		ptr->q = 4;
	return (ptr->q);
}

t_filler	*get_player(t_filler *ptr)
{
	if (ptr->line[10] == 49)
	{
		ptr->me = 79;
		ptr->opp = 88;
	}
	else
	{
		ptr->me = 88;
		ptr->opp = 79;
	}
	return (ptr);
}
