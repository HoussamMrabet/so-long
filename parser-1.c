/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser-1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 17:16:31 by hmrabet           #+#    #+#             */
/*   Updated: 2024/01/17 06:55:35 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	find_path_to_destination(char **rows, int pos_x, int pos_y, char c)
{
	if (rows[pos_x + 1][pos_y] == 'C' || rows[pos_x + 1][pos_y] == c
		|| rows[pos_x + 1][pos_y] == '0')
	{
		rows[pos_x + 1][pos_y] = 'P';
		find_path_to_destination(rows, pos_x + 1, pos_y, c);
	}
	if (rows[pos_x - 1][pos_y] == 'C' || rows[pos_x - 1][pos_y] == c
		|| rows[pos_x - 1][pos_y] == '0')
	{
		rows[pos_x - 1][pos_y] = 'P';
		find_path_to_destination(rows, pos_x - 1, pos_y, c);
	}
	if (rows[pos_x][pos_y + 1] == 'C' || rows[pos_x][pos_y + 1] == c
		|| rows[pos_x][pos_y + 1] == '0')
	{
		rows[pos_x][pos_y + 1] = 'P';
		find_path_to_destination(rows, pos_x, pos_y + 1, c);
	}
	if (rows[pos_x][pos_y - 1] == 'C' || rows[pos_x][pos_y - 1] == c
		|| rows[pos_x][pos_y - 1] == '0')
	{
		rows[pos_x][pos_y - 1] = 'P';
		find_path_to_destination(rows, pos_x, pos_y - 1, c);
	}
}

static int	is_exist(char **rows, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (rows[i])
	{
		j = 0;
		while (rows[i][j])
		{
			if (rows[i][j] == c)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	path_finder(char *str)
{
	char	**rows1;
	char	**rows2;
	int		i;
	int		j;
	int		pos[2];

	i = -1;
	rows1 = ft_split(str, '\n');
	rows2 = ft_split(str, '\n');
	while (rows1[++i])
	{
		j = -1;
		while (rows1[i][++j])
		{
			if (rows1[i][j] == 'P')
				(1) && (pos[0] = i, pos[1] = j);
		}
	}
	find_path_to_destination(rows1, pos[0], pos[1], 'C');
	find_path_to_destination(rows2, pos[0], pos[1], 'E');
	if (is_exist(rows1, 'C') || is_exist(rows2, 'E'))
		return (free_buff(rows1), free_buff(rows2), 1);
	return (free_buff(rows1), free_buff(rows2), 0);
}
