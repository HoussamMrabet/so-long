/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 11:32:02 by hmrabet           #+#    #+#             */
/*   Updated: 2024/01/15 05:04:18 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	fill_map3(t_data *data, int i, int j, int k)
{
	if (data->map[i] == 'E')
	{
		if (ft_strchr(data->map, 'C'))
		{
			mlx_put_image_to_window(data->mlx, data->mlx_win, data->ground,
				k * DIMENSION, j * DIMENSION);
			mlx_put_image_to_window(data->mlx, data->mlx_win,
				data->close_portal, k * DIMENSION, j * DIMENSION);
		}
		else
		{
			mlx_put_image_to_window(data->mlx, data->mlx_win, data->ground,
				k * DIMENSION, j * DIMENSION);
			mlx_put_image_to_window(data->mlx, data->mlx_win,
				data->open_portal, k * DIMENSION, j * DIMENSION);
		}
	}
}

static void	fill_map2(t_data *data, int i, int j, int k)
{
	if (data->map[i] == 'C')
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->ground,
			k * DIMENSION, j * DIMENSION);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->collect,
			k * DIMENSION + 15, j * DIMENSION + 15);
	}
	else if (data->map[i] == 'P')
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->ground,
			k * DIMENSION, j * DIMENSION);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->p_down,
			k * DIMENSION, j * DIMENSION);
	}
	else
		fill_map3(data, i, j, k);
}

void	fill_map(t_data *data)
{
	int		i;
	int		j;
	int		k;

	j = 0;
	k = 0;
	i = 0;
	while (data->map[i])
	{
		if (data->map[i] == '1')
			mlx_put_image_to_window(data->mlx, data->mlx_win, data->wall,
				k * DIMENSION, j * DIMENSION);
		else if (data->map[i] == '0')
			mlx_put_image_to_window(data->mlx, data->mlx_win, data->ground,
				k * DIMENSION, j * DIMENSION);
		else if (data->map[i] == '\n')
		{
			j++;
			k = -1;
		}
		else
			fill_map2(data, i, j, k);
		i++;
		k++;
	}
}
