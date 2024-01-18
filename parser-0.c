/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser-0.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 11:39:38 by hmrabet           #+#    #+#             */
/*   Updated: 2024/01/17 06:58:24 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_elements(char *str)
{
	int	i;
	int	p;
	int	e;
	int	c;

	i = 0;
	e = 0;
	p = 0;
	c = 0;
	while (str[i])
	{
		if (str[i] == 'P')
			p++;
		if (str[i] == 'E')
			e++;
		if (str[i] == 'C')
			c++;
		if (str[i] != '1' && str[i] != '0' && str[i] != 'C'
			&& str[i] != 'P' && str[i] != 'E' && str[i] != '\n')
			return (1);
		i++;
	}
	if (e != 1 || p != 1 || c < 1)
		return (1);
	return (0);
}

static int	check_empty_row(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n' && str[i + 1] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static int	check_rect(char **rows, int row_len, int col_len)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (rows[i])
	{
		while (rows[i][j])
		{
			if (i == 0 || i == (col_len - 1) || j == 0 || j == (row_len - 1))
			{
				if (rows[i][j] != '1')
					return (1);
			}
			j++;
		}
		if (j != row_len)
			return (1);
		j = 0;
		i++;
	}
	return (0);
}

void	free_buff(char	**rows)
{
	int	i;

	i = 0;
	if (rows)
	{
		while (rows[i])
		{
			free(rows[i]);
			i++;
		}
		free(rows);
	}
}

int	parser(char *map)
{
	char	**rows;
	char	*str;
	int		row_len;
	int		col_len;

	(1) && (str = NULL, rows = NULL, row_len = 0, col_len = 0);
	if (!map)
		return (1);
	str = ft_strtrim(map, "\n");
	rows = ft_split(str, '\n');
	row_len = ft_strlen(rows[0]);
	while (rows[col_len])
		col_len++;
	if (check_elements(str) || check_rect(rows, row_len, col_len)
		|| check_empty_row(str) || path_finder(str)
		|| map[ft_strlen(map) - 1] == '\n')
		return (free(map), free(str), free_buff(rows), 1);
	else
		return (free(str), free_buff(rows), 0);
}
