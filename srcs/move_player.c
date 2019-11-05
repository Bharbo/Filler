/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 13:42:05 by blanna            #+#    #+#             */
/*   Updated: 2019/09/30 13:42:09 by blanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
** Проверка постановки токена на карту
*/

static	short	try_insert_token(t_fill *data, int y, int x)
{
	int			j;
	int			i;
	int			match;

	match = 0;
	j = -1;
	while (++j < data->tok_y)
	{
		i = -1;
		while (++i < data->tok_x)
		{
			if (data->token[j][i] == '*')
			{
				if (data->map[j + y][i + x] == (data->player))
				{
					match++;
					if (match > 1)
						return (0);
				}
				else if (data->map[y + j][x + i] == (data->bot))
					return (0);
			}
		}
	}
	return ((match == 1) ? (1) : (0));
}

static	void	update_heat(t_fill *data, int res, int y, int x)
{
	data->heat_map_dot = res;
	data->ins_y = y;
	data->ins_x = x;
}

static void		check_heat(t_fill *data, int y, int x)
{
	int			j;
	int			i;
	int			res;

	res = 0;
	j = -1;
	while (++j < data->tok_y)
	{
		i = -1;
		while (++i < data->tok_x)
			res += data->heat_map[j + y][i + x];
	}
	(res < data->heat_map_dot) ? update_heat(data, res, y, x) : 0;
}

/*
** //вывод координат в output (VM ставит токен на поле боя)
*/

void			move_player(t_fill *data)
{
	int			j;
	int			i;

	j = -1;
	while (++j + (data->tok_y - 1) < data->map_y)
	{
		i = -1;
		while (++i + (data->tok_x - 1) < data->map_x)
		{
			if (try_insert_token(data, j, i))
				check_heat(data, j, i);
		}
	}
	ft_printf("%d %d\n", data->ins_y, data->ins_x);
}
