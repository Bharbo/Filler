/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 13:41:01 by blanna            #+#    #+#             */
/*   Updated: 2019/09/30 13:41:03 by blanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		print_map(char **map, int row, int col, int fd)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < row)
	{
		while (i < col)
		{
			ft_putchar_fd(map[j][i], fd);
			i++;
		}
		ft_putstr_fd("\n", fd);
		i = 0;
		j++;
	}
}

static void		print_heat_map(int **map, int row, int col, int fd)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (j < row)
	{
		while (i < col)
		{
			ft_putnbr_fd(map[j][i], fd);
			ft_putchar_fd('\t', fd);
			i++;
		}
		ft_putstr_fd("\n", fd);
		i = 0;
		j++;
	}
}

static void		print_location_token(t_fill *data, int fd_t)
{
	if (data->ins_y >= 0 && data->ins_x >= 0)
	{
		ft_putnbr_fd(data->ins_y, fd_t);
		ft_putchar_fd(' ', fd_t);
		ft_putnbr_fd(data->ins_x, fd_t);
		ft_putchar_fd('\n', fd_t);
	}
	else
	{
		ft_putnbr_fd(0, fd_t);
		ft_putchar_fd(' ', fd_t);
		ft_putnbr_fd(0, fd_t);
		ft_putchar_fd('\n', fd_t);
	}
}

void			log_map(t_fill *data, int fd)
{
	ft_putstr_fd("->plateau N - (", fd);
	ft_putnbr_fd(data->map_y, fd);
	ft_putstr_fd(")<-\n->plateau X - (", fd);
	ft_putnbr_fd(data->map_x, fd);
	ft_putstr_fd(")<-\n", fd);
	ft_putstr_fd("---+------------+----------+---\n", fd);
	print_map(data->map, data->map_y, data->map_x, fd);
	ft_putstr_fd("---+------------+----------+---\n", fd);
	print_heat_map(data->heat_map, data->map_y, data->map_x, fd);
	ft_putstr_fd("---+------------+----------+---\n", fd);
}

void			log_token_map(t_fill *data, int fd)
{
	ft_putstr_fd("->piece N - ", fd);
	ft_putnbr_fd(data->tok_y, fd);
	ft_putstr_fd("\n->piece X - ", fd);
	ft_putnbr_fd(data->tok_x, fd);
	ft_putstr_fd("\n---+------------+----------+---\n", fd);
	print_map(data->token, data->tok_y, data->tok_x, fd);
	ft_putstr_fd("---+------------+----------+---\n", fd);
	ft_putstr_fd("LOCATION - ", fd);
	ft_putstr_fd(data->player == 'O' ? "(O" : "(X", fd);
	ft_putstr_fd("): ", fd);
	print_location_token(data, fd);
	ft_putstr_fd("///---///---///---///---///---///---", fd);
	ft_putstr_fd("///---///---///---///---///---///---///\n\n\n", fd);
}
