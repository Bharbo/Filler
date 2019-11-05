/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 13:42:37 by blanna            #+#    #+#             */
/*   Updated: 2019/09/30 13:42:39 by blanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
**	Выделение памяти для токена и его считывание
*/

static	void			create_token(char ***token, int tok_y)
{
	char				*line;
	int					j;

	j = 0;
	if (!(*token = (char **)malloc(sizeof(char *) * (tok_y + 1))))
		perror("ERROR");
	while (j < tok_y)
	{
		get_next_line(0, &line);
		(*token)[j] = ft_strdup(line);
		j++;
		ft_strdel(&line);
	}
	(*token)[j] = NULL;
}

/*
**	Считывание размера поля токена "Piece у х:"
*/

void					read_token(t_fill *data)
{
	int					i;
	char				*line;

	i = 0;
	get_next_line(0, &line);
	while (!ft_isdigit(line[i]))
		i++;
	data->tok_y = ft_atoi(&line[i]);
	while (ft_isdigit(line[i]))
		i++;
	data->tok_x = ft_atoi(&line[i]);
	while (!ft_isdigit(line[i]))
		i++;
	ft_strdel(&line);
	create_token(&data->token, data->tok_y);
}
