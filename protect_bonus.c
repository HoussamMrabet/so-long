/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protect_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 01:22:23 by hmrabet           #+#    #+#             */
/*   Updated: 2024/01/17 11:00:43 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	destroy_images2(t_data *data)
{
	if (data->close_portal)
		mlx_destroy_image(data->mlx, data->close_portal);
	if (data->open_portal)
		mlx_destroy_image(data->mlx, data->open_portal);
	if (data->ground)
		mlx_destroy_image(data->mlx, data->ground);
	if (data->wall)
		mlx_destroy_image(data->mlx, data->wall);
	if (data->p_down)
		mlx_destroy_image(data->mlx, data->p_down);
	if (data->p_up)
		mlx_destroy_image(data->mlx, data->p_up);
	if (data->p_left)
		mlx_destroy_image(data->mlx, data->p_left);
	if (data->p_right)
		mlx_destroy_image(data->mlx, data->p_right);
	if (data->ennemy)
		mlx_destroy_image(data->mlx, data->ennemy);
	if (data->gold_banner)
		mlx_destroy_image(data->mlx, data->gold_banner);
	if (data->steps_banner)
		mlx_destroy_image(data->mlx, data->steps_banner);
}

void	destroy_images(t_data *data)
{
	if (data->gold1)
		mlx_destroy_image(data->mlx, data->gold1);
	if (data->gold2)
		mlx_destroy_image(data->mlx, data->gold2);
	if (data->gold3)
		mlx_destroy_image(data->mlx, data->gold3);
	if (data->gold4)
		mlx_destroy_image(data->mlx, data->gold4);
	if (data->gold5)
		mlx_destroy_image(data->mlx, data->gold5);
	if (data->gold6)
		mlx_destroy_image(data->mlx, data->gold6);
	if (data->gold7)
		mlx_destroy_image(data->mlx, data->gold7);
	if (data->gold8)
		mlx_destroy_image(data->mlx, data->gold8);
	if (data->gold9)
		mlx_destroy_image(data->mlx, data->gold9);
	if (data->gold10)
		mlx_destroy_image(data->mlx, data->gold10);
	destroy_images2(data);
}

void	cleaning(t_data *data)
{
	write(2, "Error\n invalid data!", 20);
	free(data->map);
	destroy_images(data);
	mlx_destroy_window(data->mlx, data->mlx_win);
	exit(1);
}

void	ft_protection(t_data *data)
{
	(1) && (data->steps = 0, data->coins = 0);
	data->start = clock();
	if (!data->close_portal || !data->gold1
		|| !data->gold2 || !data->gold3 || !data->gold4
		|| !data->gold5 || !data->gold6 || !data->gold7
		|| !data->gold8 || !data->gold9 || !data->gold10
		|| !data->gold_banner || !data->steps_banner || !data->ground
		|| !data->map || !data->mlx_win || !data->mlx || !data->ennemy
		|| !data->open_portal || !data->p_down || !data->p_left
		|| !data->p_right || !data->p_up || !data->wall
		|| !data->mlx || !data->mlx_win)
		cleaning(data);
}
