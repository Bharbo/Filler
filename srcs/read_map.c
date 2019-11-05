/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 13:42:20 by blanna            #+#    #+#             */
/*   Updated: 2019/09/30 13:42:22 by blanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
** Переход к карте
*/

void		go_to_map(char **line)
{
	if (!ft_strncmp(*line, "Plateau", 7))
	{
		ft_strdel(line);
		get_next_line(0, line);
	}
	ft_strdel(line);
}

/*
**	Заполнение матрицы[row][col] из потока 0
*/

void		read_map(t_fill *data, int map_y, int map_x)
{
	int		j;
	int		i;
	int		k;
	char	*line;

	j = 0;
	while (j < map_y)
	{
		k = 0;
		get_next_line(0, &line);
		while (!strchr(".OXox", line[k]))
			k++;
		i = 0;
		while (i < map_x)
		{
			(data->map)[j][i] = line[k];
			(data->heat_map)[j][i] = INT_MAX;
			i++;
			k++;
		}
		j++;
		ft_strdel(&line);
	}
}
