/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_images_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 02:14:43 by hmrabet           #+#    #+#             */
/*   Updated: 2024/01/17 10:40:49 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	init_golds_images(t_data *d)
{
	d->gold_banner = mlx_xpm_file_to_image(d->mlx,
			GOLD_BANNER, &d->width, &d->height);
	d->gold1 = mlx_xpm_file_to_image(d->mlx,
			GOLD_1, &d->width, &d->height);
	d->gold2 = mlx_xpm_file_to_image(d->mlx,
			GOLD_2, &d->width, &d->height);
	d->gold3 = mlx_xpm_file_to_image(d->mlx,
			GOLD_3, &d->width, &d->height);
	d->gold4 = mlx_xpm_file_to_image(d->mlx,
			GOLD_4, &d->width, &d->height);
	d->gold5 = mlx_xpm_file_to_image(d->mlx,
			GOLD_5, &d->width, &d->height);
	d->gold6 = mlx_xpm_file_to_image(d->mlx,
			GOLD_6, &d->width, &d->height);
	d->gold7 = mlx_xpm_file_to_image(d->mlx,
			GOLD_7, &d->width, &d->height);
	d->gold8 = mlx_xpm_file_to_image(d->mlx,
			GOLD_8, &d->width, &d->height);
	d->gold9 = mlx_xpm_file_to_image(d->mlx,
			GOLD_9, &d->width, &d->height);
	d->gold10 = mlx_xpm_file_to_image(d->mlx,
			GOLD_10, &d->width, &d->height);
}

void	init_res(t_data *d)
{
	int		i[3];

	(1) && (i[0] = 0, i[1] = -1, i[2] = 0);
	while (d->map[i[0]] && d->map[i[0]] != '\n')
		i[0]++;
	while (d->map[++i[1]])
		if (d->map[i[1]] == '\n')
			i[2]++;
	d->mlx_win = mlx_new_window(d->mlx, i[0] * DIMENSION,
			(i[2] + 1) * DIMENSION, GAME);
	d->p_down = mlx_xpm_file_to_image(d->mlx, P_DOWN, &d->width, &d->height);
	d->p_up = mlx_xpm_file_to_image(d->mlx, P_UP, &d->width, &d->height);
	d->p_left = mlx_xpm_file_to_image(d->mlx, P_LEFT, &d->width, &d->height);
	d->p_right = mlx_xpm_file_to_image(d->mlx, P_RIGHT, &d->width, &d->height);
	d->ennemy = mlx_xpm_file_to_image(d->mlx, ENNEMY, &d->width, &d->height);
	d->wall = mlx_xpm_file_to_image(d->mlx, WALL, &d->width, &d->height);
	d->ground = mlx_xpm_file_to_image(d->mlx, GROUND, &d->width, &d->height);
	d->steps_banner = mlx_xpm_file_to_image(d->mlx,
			STEPS_BANNER, &d->width, &d->height);
	d->close_portal = mlx_xpm_file_to_image(d->mlx,
			CLOSE_PORTAL, &d->width, &d->height);
	d->open_portal = mlx_xpm_file_to_image(d->mlx,
			OPEN_PORTAL, &d->width, &d->height);
	init_golds_images(d);
	ft_protection(d);
}
