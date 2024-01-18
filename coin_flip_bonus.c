/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coin_flip_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 02:13:21 by hmrabet           #+#    #+#             */
/*   Updated: 2024/01/17 10:07:38 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	set_coin2(t_data *data, int frame, int j, int k)
{
	if (frame == 4)
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->gold5,
			k * DIMENSION + 25, j * DIMENSION + 15);
	else if (frame == 5)
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->gold6,
			k * DIMENSION + 30, j * DIMENSION + 15);
	else if (frame == 6)
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->gold7,
			k * DIMENSION + 25, j * DIMENSION + 15);
	else if (frame == 7)
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->gold8,
			k * DIMENSION + 20, j * DIMENSION + 15);
	else if (frame == 8)
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->gold9,
			k * DIMENSION + 18, j * DIMENSION + 15);
	else if (frame == 9)
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->gold10,
			k * DIMENSION + 15, j * DIMENSION + 15);
}

static void	set_coin(t_data *data, int frame, int j, int k)
{
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->ground,
		k * DIMENSION, j * DIMENSION);
	if (frame == 0)
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->gold1,
			k * DIMENSION + 15, j * DIMENSION + 15);
	else if (frame == 1)
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->gold2,
			k * DIMENSION + 15, j * DIMENSION + 15);
	else if (frame == 2)
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->gold3,
			k * DIMENSION + 18, j * DIMENSION + 15);
	else if (frame == 3)
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->gold4,
			k * DIMENSION + 20, j * DIMENSION + 15);
	else
		set_coin2(data, frame, j, k);
}

int	coin_flip(t_data *data)
{
	static int	frame;
	int			i;
	int			j;
	int			k;

	(1) && (i = 0, j = 0, k = 0);
	if (clock() > data->start + 10000)
	{
		while (data->map[i])
		{
			if (data->map[i] == 'C')
				set_coin(data, frame, j, k);
			else if (data->map[i] == '\n')
				(1) && (j++, k = -1);
			(1) && (i++, k++);
		}
		frame++;
		data->start = clock();
	}
	if (frame == 10)
		frame = 0;
	return (0);
}
