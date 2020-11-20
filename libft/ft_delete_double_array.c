/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delete_double_array.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zszeredi <zszeredi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 17:22:32 by zszeredi          #+#    #+#             */
/*   Updated: 2020/11/20 17:25:02 by zszeredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_delete_double_array(char **str, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}
