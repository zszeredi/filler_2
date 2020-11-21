/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zszeredi <zszeredi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 11:23:13 by zszeredi          #+#    #+#             */
/*   Updated: 2020/11/21 17:16:45 by zszeredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

static void			printing(t_filler *ptr)
{
	ft_putnbr(ptr->coo.n);
	ft_putchar(' ');
	ft_putnbr(ptr->coo.x);
	ft_putchar(' ');
	ft_putchar('\n');
}

static t_filler		*set(t_filler *ptr)
{
	ptr->q = 0;
	ptr->counter = -1;
	ptr->end = 0;
	ptr->wall = 0;
	return (ptr);
}

int					main(void)
{
	t_filler	*ptr;

	if (!(ptr = malloc(sizeof(t_filler))))
		return (-1);
	if (get_next_line(0, &ptr->line) > 0)
		get_player(ptr);
	free(ptr->line);
	if (get_next_line(0, &ptr->line) > 0)
		create_table(ptr, ptr->line);
	free(ptr->line);
	set(ptr);
	while (get_next_line(0, &ptr->line) > 0 && ptr->end == 0)
	{
		if (ft_strstr(ptr->line, "Plateau") != NULL)
		{
			free(ptr->line);
			get_next_line(0, &ptr->line);
		}
		fill_up(ptr);
		tetro_read(ptr, ptr->line);
		printing(ptr);
	}
	delete_rest(ptr, ptr->table, ptr->lines);
	return (0);
}
