/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 23:22:50 by hmrabet           #+#    #+#             */
/*   Updated: 2024/01/17 10:08:15 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	keys_events(int key, t_data *data)
{
	if (key == 53)
		game_exit(data);
	else if (key == 123 || key == 0)
		move_left(data);
	else if (key == 124 || key == 2)
		move_right(data);
	else if (key == 125 || key == 1)
		move_down(data);
	else if (key == 126 || key == 13)
		move_up(data);
	return (0);
}

int	game_exit(t_data *data)
{
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
	exit(0);
}

void	init_res(t_data *d)
{
	int		i;
	int		j;
	int		k;

	(1 == 1) && (i = 0, j = 0, k = 0);
	while (d->map[i] && d->map[i] != '\n')
		i++;
	while (d->map[++j])
		if (d->map[j] == '\n')
			k++;
	d->mlx_win = mlx_new_window(d->mlx, i * DIMENSION,
			(k + 1) * DIMENSION, GAME);
	d->p_down = mlx_xpm_file_to_image(d->mlx, P_DOWN, &d->width, &d->height);
	d->collect = mlx_xpm_file_to_image(d->mlx, COLLECT, &d->width, &d->height);
	d->wall = mlx_xpm_file_to_image(d->mlx, WALL, &d->width, &d->height);
	d->ground = mlx_xpm_file_to_image(d->mlx, GROUND, &d->width, &d->height);
	d->close_portal = mlx_xpm_file_to_image(d->mlx,
			CLOSE_PORTAL, &d->width, &d->height);
	d->open_portal = mlx_xpm_file_to_image(d->mlx,
			OPEN_PORTAL, &d->width, &d->height);
	ft_protection(d);
}

char	*get_map(char *map)
{
	char	*full;
	char	*row;
	int		fd;

	fd = open(map, O_RDONLY);
	full = NULL;
	if (fd == -1)
	{
		write(2, "Error\n map file error!", 22);
		exit(1);
	}
	while (1)
	{
		row = get_next_line(fd);
		if (!row)
			break ;
		full = ft_strjoin_get(full, row);
		free(row);
	}
	return (full);
}

int	main(int argc, char **argv)
{
	t_data	*data;
	char	*map;

	(1) && (data = NULL, map = NULL);
	if (argc == 2 && ft_strnstr(argv[1], ".ber", ft_strlen(argv[1]))
		&& !ft_strncmp(argv[1] + (strlen(argv[1]) - 4), ".ber", 5))
	{
		map = get_map(argv[1]);
		if (parser(map))
			return (write(2, "Error\ninvalid map!", 18), 1);
		data = (t_data *)malloc(sizeof(t_data));
		if (!data)
			return (free(map), write(2, "Error\n Allocation error!", 24), 1);
		data->map = ft_strtrim(map, "\n");
		data->mlx = mlx_init();
		data->steps = 0;
		init_res(data);
		fill_map(data);
		mlx_key_hook(data->mlx_win, keys_events, data);
		mlx_hook(data->mlx_win, 17, 0, game_exit, data);
		mlx_loop(data->mlx);
	}
	else
		return (write(2, "Error\ninvalid arguments!", 24), 1);
}
