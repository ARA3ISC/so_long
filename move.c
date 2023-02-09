/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maneddam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:36:52 by maneddam          #+#    #+#             */
/*   Updated: 2023/01/03 16:37:02 by maneddam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_up(t_mlx_data *m, int check, int *c)
{
	int		x;
	int		y;
	int		count;

	count = 0;
	x = player_pos(m->table_2d).x;
	y = player_pos(m->table_2d).y;
	if (m->table_2d[x - 1][y] == 'E' && check == 1)
	{
		ft_printf("%d\n", ++*c);
		free(ft_itoa(*c));
		print_error("You won !!");
	}
	else if (m->table_2d[x - 1][y] != '1' && m->table_2d[x - 1][y] != 'E')
		count += move_on_up(m, c, x - 1, y);
	return (count);
}

int	move_right(t_mlx_data *m, int check, int *c)
{
	int		x;
	int		y;
	int		count;

	count = 0;
	x = player_pos(m->table_2d).x;
	y = player_pos(m->table_2d).y;
	if (m->table_2d[x][y + 1] == 'E' && check == 1)
	{
		ft_printf("%d\n", ++*c);
		free(ft_itoa(*c));
		print_error("You won !!");
	}
	if (m->table_2d[x][y + 1] != '1' && m->table_2d[x][y + 1] != 'E')
		count += move_on_right(m, c, x, y + 1);
	return (count);
}

int	move_down(t_mlx_data *m, int check, int *c)
{
	int		x;
	int		y;
	int		count;

	count = 0;
	x = player_pos(m->table_2d).x;
	y = player_pos(m->table_2d).y;
	if (m->table_2d[x + 1][y] == 'E' && check == 1)
	{
		ft_printf("%d\n", ++*c);
		free(ft_itoa(*c));
		print_error("You won !!");
	}
	if (m->table_2d[x + 1][y] != '1' && m->table_2d[x + 1][y] != 'E')
		count += move_on_down(m, c, x + 1, y);
	return (count);
}

int	move_left(t_mlx_data *m, int check, int *c)
{
	int		x;
	int		y;
	int		count;

	count = 0;
	x = player_pos(m->table_2d).x;
	y = player_pos(m->table_2d).y;
	if (m->table_2d[x][y - 1] == 'E' && check == 1)
	{
		ft_printf("%d\n", ++*c);
		free(ft_itoa(*c));
		print_error("You won !!");
	}
	if (m->table_2d[x][y - 1] != '1' && m->table_2d[x][y - 1] != 'E')
		count += move_on_left(m, c, x, y - 1);
	return (count);
}
