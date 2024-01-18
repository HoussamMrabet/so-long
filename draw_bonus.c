/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 18:12:11 by hmrabet           #+#    #+#             */
/*   Updated: 2024/01/17 10:52:19 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	coin_pos(int pos)
{
	static int	coin_pos;

	if (!coin_pos)
		coin_pos = pos;
	return (coin_pos);
}

static void	ft_putstep(t_data *data)
{
	char	*step;
	char	*coins;

	coins = ft_itoa(data->coins);
	step = ft_itoa(data->steps);
	mlx_put_image_to_window(data->mlx, data->mlx_win,
		data->steps_banner, DIMENSION, 2);
	mlx_string_put(data->mlx, data->mlx_win, DIMENSION * 2, 20, 0xFFFFFF, step);
	mlx_put_image_to_window(data->mlx, data->mlx_win,
		data->gold_banner, (coin_pos(0) - 3) * DIMENSION, 7);
	mlx_string_put(data->mlx, data->mlx_win,
		(coin_pos(0) - 2) * DIMENSION, 20, 0xFFFFFF, coins);
	free(coins);
	free(step);
}

static void	fill_map3(t_data *data, int *i, char c)
{
	if (data->map[i[0]] == 'P')
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->ground,
			i[2] * DIMENSION, i[1] * DIMENSION);
		if (c == 'u')
			mlx_put_image_to_window(data->mlx, data->mlx_win, data->p_up,
				i[2] * DIMENSION, i[1] * DIMENSION);
		else if (c == 'd')
			mlx_put_image_to_window(data->mlx, data->mlx_win, data->p_down,
				i[2] * DIMENSION, i[1] * DIMENSION);
		else if (c == 'l')
			mlx_put_image_to_window(data->mlx, data->mlx_win, data->p_left,
				i[2] * DIMENSION, i[1] * DIMENSION);
		else if (c == 'r')
			mlx_put_image_to_window(data->mlx, data->mlx_win, data->p_right,
				i[2] * DIMENSION, i[1] * DIMENSION);
	}
	else if (data->map[i[0]] == 'N')
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->ground,
			i[2] * DIMENSION, i[1] * DIMENSION);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->ennemy,
			i[2] * DIMENSION, i[1] * DIMENSION);
	}
}

static void	fill_map2(t_data *data, int *i, char c)
{
	if (data->map[i[0]] == '1')
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->wall,
			i[2] * DIMENSION, i[1] * DIMENSION);
	}
	else if (data->map[i[0]] == '0')
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->ground,
			i[2] * DIMENSION, i[1] * DIMENSION);
	else if (data->map[i[0]] == '\n')
	{
		i[1] += 1;
		coin_pos(i[0]);
		i[2] = -1;
	}
	else
		fill_map3(data, i, c);
}

void	fill_map(t_data *data, char c)
{
	int		i[3];

	i[0] = 0;
	i[1] = 0;
	i[2] = 0;
	while (data->map[i[0]])
	{
		if (data->map[i[0]] == 'E')
		{
			mlx_put_image_to_window(data->mlx, data->mlx_win, data->ground,
				i[2] * DIMENSION, i[1] * DIMENSION);
			if (ft_strchr(data->map, 'C'))
				mlx_put_image_to_window(data->mlx, data->mlx_win,
					data->close_portal, i[2] * DIMENSION, i[1] * DIMENSION);
			else
				mlx_put_image_to_window(data->mlx, data->mlx_win,
					data->open_portal, i[2] * DIMENSION, i[1] * DIMENSION);
		}
		else
			fill_map2(data, i, c);
		i[0] += 1;
		i[2] += 1;
	}
	ft_putstep(data);
}
