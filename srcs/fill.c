/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zszeredi <zszeredi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 11:37:44 by zszeredi          #+#    #+#             */
/*   Updated: 2020/11/20 11:41:53 by zszeredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

static t_filler			*insert(t_filler *ptr, char c, t_coords coord)
{
	if (ptr->table[coord.n][coord.x] != '\0'
			&& ptr->table[coord.n][coord.x] == '.')
		ptr->table[coord.n][coord.x] = c;
	return (ptr);
}

static t_filler			*bridge(t_filler *ptr, int x, char c)
{
	ptr->coo.x = x - 4;
	insert(ptr, c, ptr->coo);
	return (ptr);
}

static t_filler			*first(t_filler *ptr, int counter)
{

	if (counter == -1)
	{
		ptr->me_s = coord_copy(ptr->me_s, ptr->coo.x, ptr->coo.n);
		ptr->counter = 0;
	}
	if (counter == 0)
	{
		ptr->me_line = ptr->coo.n;
		ptr->up = coord_copy(ptr->up, ptr->coo.x, ptr->coo.n);
		ptr->counter = 1;
	}
	return (ptr);
}

static t_filler			*read_chara(t_filler *ptr, char *line, int n)
{
	int	x;

	x = 0;
	ptr->coo.n = n;
	while (line[x] != '\0')
	{
		if (line[x] == ptr->me)
		{
			bridge(ptr, x, ptr->me);
			if (ptr->counter == -1)
				first(ptr, ptr->counter);
			if (ptr->counter == 0)
				first(ptr, ptr->counter);	
			ptr->down = coord_copy(ptr->down, ptr->coo.x, ptr->coo.n);
		}
		else if (line[x] == ptr->opp)
		{
			ptr->opp_line = ptr->coo.n;
			bridge(ptr, x, ptr->opp);
		}
		x++;
	}
	return (ptr);
}

t_filler				*fill_up(t_filler *ptr)
{
	int			n;
	static int	i;

	n = 0;
	i = 0;
	while (ft_strstr(ptr->line, "Piece") == NULL)
	{
		free(ptr->line);
		get_next_line(0, &ptr->line);
		if ((ft_strchr(ptr->line, ptr->me)) != 0 ||
				(ft_strchr(ptr->line, ptr->opp)) != 0)
			read_chara(ptr, ptr->line, n);
		n++;
		i++;
	}
	if (ptr->q == 0)
		ptr->q = quadrant(ptr);
	ptr->counter = 0;
	return (ptr);
}
