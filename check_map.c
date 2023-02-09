/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maneddam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 00:42:57 by maneddam          #+#    #+#             */
/*   Updated: 2023/01/02 23:03:27 by maneddam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*read_map(char *argv)
{
	int		i;
	int		check;
	char	*line;
	char	*full_map;
	int		fd;

	(void)argv;
	full_map = ft_calloc(1, 1);
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		print_error("Error\nFile not found !");
	i = 0;
	check = 0;
	line = get_next_line(fd);
	if (line == NULL)
		print_error("Error\nNo line error !!");
	while (line != NULL)
	{
		full_map = ft_strjoin_get(full_map, line);
		free(line);
		line = get_next_line(fd);
	}
	if (full_map[0] == '\n')
		print_error("Error\nEmpty line error !!");
	return (full_map);
}

void	wall_validity(char *full_map)
{
	char	**table_2d;
	int		table_len;
	int		i;

	i = 0;
	table_2d = ft_split(full_map, '\n');
	while (table_2d[i] != NULL)
		i++;
	table_len = i;
	i = 0;
	while (table_2d[0][i])
	{
		if (table_2d[0][i] != '1' || table_2d[table_len - 1][i] != '1')
			print_error("Error\nInvalid wall !!");
		i++;
	}
	i = 1;
	while (table_2d[i] != NULL)
	{
		if (table_2d[i][0] != '1' ||
			table_2d[i][ft_strlen(table_2d[i]) - 1] != '1')
			print_error("Error\nInvalid wall !!");
		i++;
	}
	ft_free(table_2d, get_dimens(table_2d).x);
}

void	check_items(char *full_map)
{
	int	i;
	int	t_players;
	int	doors;
	int	collect;

	i = 0;
	t_players = 0;
	doors = 0;
	collect = 0;
	while (full_map[i])
	{
		if (full_map[i] == 'E')
			doors++;
		else if (full_map[i] == 'P')
			t_players++;
		else if (full_map[i] == 'C')
			collect++;
		i++;
	}
	if (doors != 1 || t_players != 1)
		print_error("Error\nIt must be just 1 door and 1 t_player !!");
	else if (collect == 0)
		print_error("Error\nIt must be at least 1 collectible !!");
}

void	form_validity(char *full_map)
{
	char	**table_2d;
	int		i;
	int		table_len;

	table_2d = ft_split(full_map, '\n');
	table_len = ft_strlen(table_2d[0]);
	i = 0;
	while (table_2d[i] != NULL)
	{
		if (ft_strlen(table_2d[i]) != table_len)
			print_error("Error\nInvalid wall form !!");
		i++;
	}
	ft_free(table_2d, get_dimens(table_2d).x);
}

void	check_empty_lines(char *full_map)
{
	int	i;

	i = 0;
	while (full_map[i])
	{
		if (full_map[i] == '\n' && full_map[i + 1] == '\n')
			print_error("Error\nInvalid map form !!");
		i++;
	}
}
