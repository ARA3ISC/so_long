/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maneddam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 23:34:46 by maneddam          #+#    #+#             */
/*   Updated: 2022/12/22 04:39:48 by maneddam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line/get_next_line.h"
#include "./libft/libft.h"
#include "./printf/ft_printf.h"
#include "mlx.h"
#include "so_long.h"

void	checking(int argc, char **argv)
{
	char		*fmap;
	t_player	p;
	char		**table_2d;

	fmap = read_map(argv[1]);
	table_2d = ft_split(fmap, '\n');
	p = player_pos(table_2d);
	check_arg(argc, argv);
	wall_validity(fmap);
	check_items(fmap);
	form_validity(fmap);
	check_empty_lines(fmap);
	check_characters(fmap);
	check_player_path(table_2d, fmap, p);
	ft_free(table_2d, get_dimens(table_2d).x);
	free(fmap);
}

int	closed(t_mlx_data *m)
{
	ft_printf("You closed the game !");
	mlx_destroy_window(m->mlx_ptr, m->wind_ptr);
	exit(0);
}

int	exec(int keycode, t_mlx_data *m)
{
	t_player	p;
	static int	count;
	static int	check;
	static int	c;

	p = player_pos(m->table_2d);
	if (keycode == ESC)
	{
		ft_printf("You closed the game using ESC key !");
		mlx_destroy_window(m->mlx_ptr, m->wind_ptr);
		exit(0);
	}
	if (count == count_c2(m))
		check = 1;
	if (keycode == UP || keycode == 13)
		count += move_up(m, check, &c);
	if (keycode == RIGHT || keycode == 2)
		count += move_right(m, check, &c);
	if (keycode == DOWN || keycode == 1)
		count += move_down(m, check, &c);
	if (keycode == LEFT || keycode == 0)
		count += move_left(m, check, &c);
	return (count);
}

int	animate(t_mlx_data *m)
{
	if (m->timer > 800)
	{
		m->timer = 0;
		rotate_img(m);
		m->index++;
		m->index_en++;
	}
	if (m->index == 7)
		m->index = 0;
	if (m->index_en == 18)
		m->index_en = 0;
	m->timer++;
	return (0);
}

int	main(int argc, char **argv)
{
	t_mlx_data	m;
	t_player	p;
	t_collected	c;
	char		*fmap;

	c.move = 0;
	m.timer = 0;
	m.index = 0;
	m.index_en = 0;
	m.argv = argv[1];
	fmap = read_map(argv[1]);
	m.table_2d = ft_split(fmap, '\n');
	p = get_dimens(m.table_2d);
	checking(argc, argv);
	m.mlx_ptr = mlx_init();
	m.wind_ptr = mlx_new_window(m.mlx_ptr, 60 * p.y, 60 * p.x, "game 2D");
	display_map(m.table_2d, &m);
	mlx_hook(m.wind_ptr, 2, 0, exec, &m);
	mlx_hook(m.wind_ptr, 17, 0, closed, &m);
	mlx_loop_hook(m.mlx_ptr, animate, &m);
	mlx_loop(m.mlx_ptr);
	free(fmap);
	ft_free(m.table_2d, get_dimens(m.table_2d).x);
	return (0);
}
