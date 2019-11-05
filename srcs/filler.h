/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 13:40:24 by blanna            #+#    #+#             */
/*   Updated: 2019/09/30 13:40:37 by blanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**				***DATA***
**
**	player			- Я
**	bot				- бот
**	map_x, map_y	- размер поля боя
**	map 			- поле боя
**	heat_map		- тепловая карта приоритетности
**  tok_y, tok_x	- размер поля с токеном
**	token			- поле, содержащее токен
**	ins_y, ins_x	- координаты подаваемые в filler_vm
**	line			- для сохранения ввода
*/

#ifndef FILLER_H
# define FILLER_H

# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"
# include "../libft/includes/get_next_line.h"

typedef	struct			s_fill
{
	char				player;
	char				bot;
	char				**map;
	int					map_y;
	int					map_x;
	char				**token;
	int					tok_y;
	int					tok_x;
	int					**heat_map;
	int					heat_map_dot;
	int					ins_y;
	int					ins_x;
	char				*line;
}						t_fill;

void					go_to_map(char **line);
void					read_map(t_fill *data, int map_y, int map_x);
void					read_token(t_fill *data);
void					move_player(t_fill *data);
void					memory_heat_map(t_fill *data, int map_y, int map_x);
void					create_heat_map(t_fill *data);
void					log_map(t_fill *data, int fd);
void					log_token_map(t_fill *data, int fd);
void					free_heat_map(int **map, int row);
void					free_map(char **map, int row);

#endif
