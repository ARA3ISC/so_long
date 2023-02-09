/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maneddam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 00:44:05 by maneddam          #+#    #+#             */
/*   Updated: 2023/01/03 15:42:49 by maneddam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./get_next_line/get_next_line.h"
# include "./libft/libft.h"
# include "./printf/ft_printf.h"
# include "mlx.h"

# define ESC 53
# define RIGHT 124
# define LEFT 123
# define UP 126
# define DOWN 125

void		print_error(char *msg);
char		*read_map(char *argv);
void		wall_validity(char *full_map);
void		check_items(char *full_map);
void		form_validity(char *full_map);
void		check_empty_lines(char *full_map);
void		check_arg(int argc, char **argv);
void		check_characters(char *full_map);

typedef struct node
{
	int		x;
	int		y;
}			t_player;

t_player	player_pos(char **table_2d);
int			check_collect_path(char **table_2d, int x, int y);
int			check_exit_path(char **table_2d, int x, int y);
t_player	get_dimens(char **table_2d);
void		check_player_path(char **table_2d, char *fmap, t_player p);
int			count_c(char **table_2d);

typedef struct s_mlx_data
{
	void	*mlx_ptr;
	void	*wind_ptr;
	void	*img_ptr;
	void	*coin_ptr[8];
	void	*enemy_ptr[19];
	char	**table_2d;
	char	*argv;
	int		timer;
	int		index;
	int		index_en;
}			t_mlx_data;

int			count_c2(t_mlx_data *m);

typedef struct s_collected
{
	int		count;
	int		move;
	int		x_c;
	int		y_c;
}			t_collected;

int			move_up(t_mlx_data *m, int check, int *move);
int			move_right(t_mlx_data *m, int check, int *move);
int			move_down(t_mlx_data *m, int check, int *move);
int			move_left(t_mlx_data *m, int check, int *move);
void		display_map(char **table_2d, t_mlx_data *m);

void		swap_img_up(t_mlx_data *m, int x, int y);
void		swap_img_right(t_mlx_data *m, int x, int y);
void		swap_img_down(t_mlx_data *m, int x, int y);
void		swap_img_left(t_mlx_data *m, int x, int y);

void		display_ground(t_mlx_data *m, int i, int j);
void		display_wall(t_mlx_data *m, int i, int j);
void		display_other_items(t_mlx_data *m, char *item, int i, int j);
void		display_coins(t_mlx_data *m, int i, int j);
void		display_enemy(t_mlx_data *m, int i, int j);
void		rotate_img(t_mlx_data *m);
void		display_map(char **table_2d, t_mlx_data *m);
int			move_on_up(t_mlx_data *m, int *c, int x, int y);
int			move_on_right(t_mlx_data *m, int *c, int x, int y);
int			move_on_down(t_mlx_data *m, int *c, int x, int y);
int			move_on_left(t_mlx_data *m, int *c, int x, int y);

#endif
