/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 01:22:23 by hmrabet           #+#    #+#             */
/*   Updated: 2024/01/17 09:28:05 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_protection(t_data *data)
{
	if (!data->close_portal || !data->collect || !data->ground
		|| !data->map || !data->mlx_win || !data->mlx
		|| !data->open_portal || !data->p_down || !data->wall)
	{
		write(2, "Error\n invalid data!", 20);
		free(data->map);
		if (data->close_portal)
			mlx_destroy_image(data->mlx, data->close_portal);
		if (data->collect)
			mlx_destroy_image(data->mlx, data->collect);
		if (data->ground)
			mlx_destroy_image(data->mlx, data->ground);
		if (data->open_portal)
			mlx_destroy_image(data->mlx, data->open_portal);
		if (data->p_down)
			mlx_destroy_image(data->mlx, data->p_down);
		if (data->wall)
			mlx_destroy_image(data->mlx, data->wall);
		mlx_destroy_window(data->mlx, data->mlx_win);
		exit(1);
	}
}
