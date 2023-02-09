/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_items.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maneddam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 21:14:14 by maneddam          #+#    #+#             */
/*   Updated: 2023/01/06 16:19:27 by maneddam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_ground(t_mlx_data *m, int i, int j)
{
	int	width;
	int	height;

	m->img_ptr = mlx_xpm_file_to_image(m->mlx_ptr, "./textures/l2ard.xpm",
			&width, &height);
	if (!m->img_ptr)
		print_error("Error : corrupted xpm");
	mlx_put_image_to_window(m->mlx_ptr, m->wind_ptr, m->img_ptr, 60 * j, 60
		* i);
}

void	display_wall(t_mlx_data *m, int i, int j)
{
	int	width;
	int	height;

	m->img_ptr = mlx_xpm_file_to_image(m->mlx_ptr, "./textures/l7it.xpm",
			&width, &height);
	if (!m->img_ptr)
		print_error("Error : corrupted xpm");
	mlx_put_image_to_window(m->mlx_ptr, m->wind_ptr, m->img_ptr, 60 * j, 60
		* i);
}

void	fill_coin_ptr(t_mlx_data *m, int *width, int *height, int k)
{
	char	*k_str;
	char	*path;
	char	*r;
	char	*item;
	int		l;

	path = "./textures/coins/coin";
	l = 8;
	if (l != 8)
		print_error("Error occured !!");
	while (k < 8)
	{
		k_str = ft_itoa(k);
		r = ft_strjoin(path, k_str);
		item = ft_strjoin(r, ".xpm");
		m->coin_ptr[k] = mlx_xpm_file_to_image(m->mlx_ptr, item, width, height);
		if (!m->coin_ptr[k])
			print_error("Error\ncorrupted xpm !!");
		free(r);
		free(item);
		free(k_str);
		k++;
	}
}

void	display_coins(t_mlx_data *m, int i, int j)
{
	int	width;
	int	height;
	int	k;

	k = 0;
	display_ground(m, i, j);
	fill_coin_ptr(m, &width, &height, k);
	mlx_put_image_to_window(m->mlx_ptr, m->wind_ptr, m->coin_ptr[m->index], 60
		* j, 60 * i);
	if (!m->coin_ptr[m->index])
		print_error("Error\ncorrupted xpm");
}

void	display_other_items(t_mlx_data *m, char *item, int i, int j)
{
	int	width;
	int	height;

	display_ground(m, i, j);
	m->img_ptr = mlx_xpm_file_to_image(m->mlx_ptr,
			item, &width, &height);
	if (!m->img_ptr)
		print_error("Error : error occured !!");
	mlx_put_image_to_window(m->mlx_ptr, m->wind_ptr, m->img_ptr, 60 * j, 60
		* i);
}
