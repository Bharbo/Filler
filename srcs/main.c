/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 13:41:13 by blanna            #+#    #+#             */
/*   Updated: 2019/09/30 13:41:14 by blanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
**	Инициализация игроков
*/

static	void	init_player(t_fill *data)
{
	char		*line;

	get_next_line(0, &line);
	if (!ft_strncmp("$$$ exec p1 :", line, 13))
	{
		data->player = 'O';
		data->bot = 'X';
	}
	else
	{
		data->player = 'X';
		data->bot = 'O';
	}
	ft_strdel(&line);
}

/*
** Считываение размера карты. "Plateau y x".
*/

static	void	read_size_map(t_fill *data)
{
	int			i;
	char		*line;

	i = 0;
	get_next_line(0, &line);
	while (!ft_isdigit(line[i]))
		i++;
	data->map_y = ft_atoi(&line[i]);
	while (ft_isdigit(line[i]))
		i++;
	while (!ft_isdigit(line[i]))
		i++;
	data->map_x = ft_atoi(&line[i]);
	ft_strdel(&line);
}

/*
** Выделение памяти для карты
*/

static	void	memory_map(t_fill *data, int map_y, int map_x)
{
	int			j;

	j = 0;
	if (!(data->map = (char **)malloc(sizeof(char *) * (map_y + 1))))
		perror("ERROR");
	while (j < map_y)
	{
		if (!(data->map[j] = ft_strnew(map_x + 1)))
			perror("ERROR");
		j++;
	}
	(data->map)[j] = NULL;
}

static void		get_player(t_fill *data, int fd)
{
	init_player(data);
	ft_putstr_fd("-> player - (", fd);
	ft_putchar_fd(data->player, fd);
	ft_putstr_fd(") <-\n", fd);
	ft_putstr_fd("---+------------+----------+---\n", fd);
}

int				main(void)
{
	t_fill		data;
	int			fd;

	fd = open("log/log.txt", O_WRONLY);
	if (fd == -1)
		perror("ERROR");
	get_player(&data, fd);
	read_size_map(&data);
	memory_map(&data, data.map_y, data.map_x);
	memory_heat_map(&data, data.map_y, data.map_x);
	while (get_next_line(0, &data.line) > 0)
	{
		go_to_map(&data.line);
		read_map(&data, data.map_y, data.map_x);
		read_token(&data);
		create_heat_map(&data);
		move_player(&data);
		log_map(&data, fd);
		log_token_map(&data, fd);
		free_map(data.token, data.tok_y);
	}
	free_heat_map(data.heat_map, data.map_y);
	free_map(data.map, data.map_y);
	close(fd);
	return (0);
}
