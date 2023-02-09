/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extend_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maneddam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 06:19:56 by maneddam          #+#    #+#             */
/*   Updated: 2023/01/06 15:18:27 by maneddam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_on_up(t_mlx_data *m, int *c, int x, int y)
{
	char	*itoa_str;
	int		count;

	count = 0;
	if (m->table_2d[x][y] == 'I')
		print_error("You died !!");
	if (m->table_2d[x][y] == 'C')
	{
		count++;
		m->table_2d[x][y] = '0';
	}
	swap_img_up(m, player_pos(m->table_2d).x - 1, y);
	ft_printf("%d\n", ++*c);
	display_wall(m, 0, get_dimens(m->table_2d).y / 2);
	itoa_str = ft_itoa(*c);
	mlx_string_put(m->mlx_ptr, m->wind_ptr, get_dimens(m->table_2d).y * 60 / 2,
		25, 0xfffffff, itoa_str);
	display_ground(m, x + 1, y);
	display_other_items(m, "./textures/lhero.xpm", x, y);
	free(itoa_str);
	return (count);
}

int	move_on_right(t_mlx_data *m, int *c, int x, int y)
{
	char	*itoa_str;
	int		count;

	count = 0;
	if (m->table_2d[x][y] == 'I')
		print_error("You died !!");
	if (m->table_2d[x][y] == 'C')
	{
		count++;
		m->table_2d[x][y] = '0';
	}
	swap_img_right(m, x, player_pos(m->table_2d).y + 1);
	ft_printf("%d\n", ++*c);
	display_wall(m, 0, get_dimens(m->table_2d).y / 2);
	itoa_str = ft_itoa(*c);
	mlx_string_put(m->mlx_ptr, m->wind_ptr, get_dimens(m->table_2d).y * 60 / 2,
		25, 0xfffffff, itoa_str);
	display_ground(m, x, y - 1);
	display_other_items(m, "./textures/lhero.xpm", x, y);
	free(itoa_str);
	return (count);
}

int	move_on_down(t_mlx_data *m, int *c, int x, int y)
{
	char	*itoa_str;
	int		count;

	count = 0;
	if (m->table_2d[x][y] == 'I')
		print_error("You died !!");
	if (m->table_2d[x][y] == 'C')
	{
		count++;
		m->table_2d[x][y] = '0';
	}
	swap_img_down(m, player_pos(m->table_2d).x + 1, y);
	ft_printf("%d\n", ++*c);
	display_wall(m, 0, get_dimens(m->table_2d).y / 2);
	itoa_str = ft_itoa(*c);
	mlx_string_put(m->mlx_ptr, m->wind_ptr, get_dimens(m->table_2d).y * 60 / 2,
		25, 0xfffffff, itoa_str);
	display_ground(m, x - 1, y);
	display_other_items(m, "./textures/lhero.xpm", x, y);
	free(itoa_str);
	return (count);
}

int	move_on_left(t_mlx_data *m, int *c, int x, int y)
{
	char	*itoa_str;
	int		count;

	count = 0;
	if (m->table_2d[x][y] == 'I')
		print_error("You died !!");
	if (m->table_2d[x][y] == 'C')
	{
		count++;
		m->table_2d[x][y] = '0';
	}
	swap_img_left(m, x, player_pos(m->table_2d).y - 1);
	ft_printf("%d\n", ++*c);
	display_wall(m, 0, get_dimens(m->table_2d).y / 2);
	itoa_str = ft_itoa(*c);
	mlx_string_put(m->mlx_ptr, m->wind_ptr, get_dimens(m->table_2d).y * 60 / 2,
		25, 0xfffffff, itoa_str);
	display_ground(m, x, y + 1);
	display_other_items(m, "./textures/lhero.xpm", x, y);
	free(itoa_str);
	return (count);
}
