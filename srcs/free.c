/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 15:38:32 by blanna            #+#    #+#             */
/*   Updated: 2019/09/30 15:38:34 by blanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	free_heat_map(int **map, int row)
{
	while (row)
	{
		free(map[row - 1]);
		map[row - 1] = NULL;
		row--;
	}
	free(map);
}

void	free_map(char **map, int row)
{
	while (row)
	{
		free(map[row - 1]);
		map[row - 1] = NULL;
		row--;
	}
	free(map);
}
