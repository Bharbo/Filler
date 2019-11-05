/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heat_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 13:40:45 by blanna            #+#    #+#             */
/*   Updated: 2019/09/30 13:40:51 by blanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
** Обновление карты приоритетности
*/

static	void	update(t_fill *data, int y, int x)
{
	int			j;
	int			i;
	int			tmp;

	data->heat_map[y][x] = 0;
	j = -1;
	while (++j < data->map_y)
	{
		i = -1;
		while (++i < data->map_x)
		{
			if (data->map[j][i] != data->bot)
			{
				tmp = ABS(j - y) + ABS(i - x);
				data->heat_map[j][i] = ft_min(tmp, data->heat_map[j][i]);
			}
		}
	}
}

/*
** Поиск нод занятых ботом и обновление карты приоритетности
*/

void			create_heat_map(t_fill *data)
{
	int			j;
	int			i;

	j = 0;
	while (j < data->map_y)
	{
		i = 0;
		while (i < data->map_x)
		{
			if (data->map[j][i] == data->bot)
				update(data, j, i);
			i++;
		}
		j++;
	}
	data->heat_map_dot = INT_MAX;
	data->ins_y = 0;
	data->ins_x = 0;
}

/*
** Выделение памяти для карты приоритетности
*/

void			memory_heat_map(t_fill *data, int map_y, int map_x)
{
	int			j;

	j = 0;
	if (!(data->heat_map = (int **)malloc(sizeof(int *) * (map_y))))
		perror("ERROR");
	while (j < map_y)
	{
		if (!(data->heat_map[j] = (int *)malloc(sizeof(int) * (map_x))))
			perror("ERROR");
		j++;
	}
}
