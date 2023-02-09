/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dimens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maneddam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 21:30:22 by maneddam          #+#    #+#             */
/*   Updated: 2022/12/30 02:46:53 by maneddam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_player	get_dimens(char **table_2d)
{
	int			width;
	int			height;
	int			i;
	t_player	p;

	i = 0;
	while (table_2d[i] != NULL)
		i++;
	width = ft_strlen(table_2d[0]);
	height = i;
	p.x = height;
	p.y = width;
	return (p);
}
