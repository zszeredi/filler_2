/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zszeredi <zszeredi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 11:27:08 by zszeredi          #+#    #+#             */
/*   Updated: 2020/11/20 11:30:05 by zszeredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

t_coords	coord_copy(t_coords coo, int j, int i)
{
	coo.x = j;
	coo.n = i;
	return (coo);
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
