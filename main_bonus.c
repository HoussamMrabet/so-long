/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 18:13:57 by hmrabet           #+#    #+#             */
/*   Updated: 2024/01/17 11:01:56 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
	destroy_images(data);
	mlx_destroy_window(data->mlx, data->mlx_win);
	exit(0);
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
			return (write(2, "Error\n Invalid map!", 19), 1);
		data = (t_data *)malloc(sizeof(t_data));
		if (!data)
			return (free(map), write(2, "Error\n Allocation error!", 24), 1);
		data->map = ft_strtrim(map, "\n");
		data->mlx = mlx_init();
		init_res(data);
		fill_map(data, 'd');
		mlx_key_hook(data->mlx_win, keys_events, data);
		mlx_hook(data->mlx_win, 17, 0, game_exit, data);
		mlx_loop_hook(data->mlx, coin_flip, data);
		mlx_loop(data->mlx);
	}
	else
		return (write(2, "Error\ninvalid arguments!", 24), 1);
}
