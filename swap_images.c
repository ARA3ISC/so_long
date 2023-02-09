/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maneddam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:49:37 by maneddam          #+#    #+#             */
/*   Updated: 2022/12/29 23:07:27 by maneddam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	swap_img_up(t_mlx_data *m, int x, int y)
{
	char	tmp;

	tmp = m->table_2d[x + 1][y];
	m->table_2d[x + 1][y] = m->table_2d[x][y];
	m->table_2d[x][y] = tmp;
}

void	swap_img_right(t_mlx_data *m, int x, int y)
{
	char	tmp;

	tmp = m->table_2d[x][y];
	m->table_2d[x][y] = m->table_2d[x][y - 1];
	m->table_2d[x][y - 1] = tmp;
}

void	swap_img_down(t_mlx_data *m, int x, int y)
{
	char	tmp;

	tmp = m->table_2d[x - 1][y];
	m->table_2d[x - 1][y] = m->table_2d[x][y];
	m->table_2d[x][y] = tmp;
}

void	swap_img_left(t_mlx_data *m, int x, int y)
{
	char	tmp;

	tmp = m->table_2d[x][y];
	m->table_2d[x][y] = m->table_2d[x][y + 1];
	m->table_2d[x][y + 1] = tmp;
}
