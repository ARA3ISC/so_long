/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maneddam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 00:55:06 by maneddam          #+#    #+#             */
/*   Updated: 2023/01/02 01:28:51 by maneddam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_error(char *msg)
{
	ft_printf("%s", msg);
	exit(1);
}

void	check_arg(int argc, char **argv)
{
	int	fd;
	int	i;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		i = 0;
		if (fd == -1)
		{
			ft_printf("Error\nNo such file '%s'", argv[1]);
			exit(1);
		}
		while (argv[1][i])
			i++;
		i--;
		if (argv[1][i] != 'r' || argv[1][--i] != 'e' || argv[1][--i] != 'b'
			|| argv[1][--i] != '.')
			print_error("Error\nArgument extension must be as follow '.ber' !!");
	}
	else
	{
		ft_printf("Error\nIt must be exacly one argument !!");
		exit(1);
	}
}

void	check_characters(char *full_map)
{
	int	i;

	i = 0;
	while (full_map[i])
	{
		if (full_map[i] != '1' && full_map[i] != '0' && full_map[i] != 'E'
			&& full_map[i] != 'P' && full_map[i] != 'C' && full_map[i] != '\n'
			&& full_map[i] != 'I')
			print_error("Error \nInvalid character !!");
		i++;
	}
}

t_player	player_pos(char **table_2d)
{
	t_player	p;
	int			i;
	int			j;

	p.x = 0;
	p.y = 0;
	i = 0;
	while (table_2d[i])
	{
		j = 0;
		while (table_2d[i][j])
		{
			if (table_2d[i][j] == 'P')
			{
				p.x = i;
				p.y = j;
				return (p);
			}
			j++;
		}
		i++;
	}
	return (p);
}

void	check_player_path(char **table_2d, char *fmap, t_player p)
{
	int		nc;
	int		collected;
	char	**tab;
	int		got_door;

	nc = count_c(table_2d);
	collected = check_collect_path(table_2d, p.x, p.y);
	tab = ft_split(fmap, '\n');
	got_door = check_exit_path(tab, p.x, p.y);
	if (collected != nc)
		print_error("Error\nInvalid path to collectible !!");
	else if (got_door != 1)
		print_error("Error\nInvalid path to the door !!");
	ft_free(tab, get_dimens(tab).x);
}
