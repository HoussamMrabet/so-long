/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 18:14:39 by hmrabet           #+#    #+#             */
/*   Updated: 2024/01/17 04:07:02 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	check_collect(t_data *data)
{
	if (!ft_strchr(data->map, 'C'))
	{
		ft_printf("steps : %d\n", ++data->steps);
		ft_printf("\033[1;92m");
		ft_printf(WON1 WON1_1 WON2 WON2_1 WON3 WON3_1);
		ft_printf(WON4 WON4_1 WON5 WON5_1 WON6 WON6_1);
		ft_printf(WON7 WON7_1 WON8 WON8_1 WON9 WON9_1);
		ft_printf(WON10 WON10_1 WON11 WON11_1);
		ft_printf("\033[0m");
		game_exit(data);
	}
}

int	move_down(t_data *data)
{
	int	line_len;
	int	p_pose;

	(1) && (line_len = 0, p_pose = 0);
	while (data->map[line_len] && data->map[line_len] != '\n')
		line_len++;
	while (data->map[p_pose] && data->map[p_pose] != 'P')
		p_pose++;
	if (data->map[p_pose + line_len + 1] == '0'
		|| data->map[p_pose + line_len + 1] == 'C')
	{
		if (data->map[p_pose + line_len + 1] == 'C')
			data->coins++;
		data->map[p_pose] = '0';
		data->map[p_pose + line_len + 1] = 'P';
		ft_printf("steps : %d\n", ++data->steps);
	}
	else if (data->map[p_pose + line_len + 1] == 'N')
	{
		print_game_over();
		game_exit(data);
	}
	else if (data->map[p_pose + line_len + 1] == 'E')
		check_collect(data);
	return (fill_map(data, 'd'), 0);
}

int	move_up(t_data *data)
{
	int	line_len;
	int	p_pose;

	(1) && (line_len = 0, p_pose = 0);
	while (data->map[line_len] && data->map[line_len] != '\n')
		line_len++;
	while (data->map[p_pose] && data->map[p_pose] != 'P')
		p_pose++;
	if (data->map[p_pose - line_len - 1] == '0'
		|| data->map[p_pose - line_len - 1] == 'C')
	{
		if (data->map[p_pose - line_len - 1] == 'C')
			data->coins++;
		data->map[p_pose] = '0';
		data->map[p_pose - line_len - 1] = 'P';
		ft_printf("steps : %d\n", ++data->steps);
	}
	else if (data->map[p_pose - line_len - 1] == 'N')
	{
		print_game_over();
		game_exit(data);
	}
	else if (data->map[p_pose - line_len - 1] == 'E')
		check_collect(data);
	return (fill_map(data, 'u'), 0);
}

int	move_right(t_data *data)
{
	int	p_pose;

	p_pose = 0;
	while (data->map[p_pose] && data->map[p_pose] != 'P')
		p_pose++;
	if (data->map[p_pose + 1] == '0' || data->map[p_pose + 1] == 'C')
	{
		if (data->map[p_pose + 1] == 'C')
			data->coins++;
		data->map[p_pose] = '0';
		data->map[p_pose + 1] = 'P';
		ft_printf("steps : %d\n", ++data->steps);
	}
	else if (data->map[p_pose + 1] == 'N')
	{
		print_game_over();
		game_exit(data);
	}
	else if (data->map[p_pose + 1] == 'E')
		check_collect(data);
	fill_map(data, 'r');
	return (0);
}

int	move_left(t_data *data)
{
	int	p_pose;

	p_pose = 0;
	while (data->map[p_pose] && data->map[p_pose] != 'P')
		p_pose++;
	if (data->map[p_pose - 1] == '0' || data->map[p_pose - 1] == 'C')
	{
		if (data->map[p_pose - 1] == 'C')
			data->coins++;
		data->map[p_pose] = '0';
		data->map[p_pose - 1] = 'P';
		ft_printf("steps : %d\n", ++data->steps);
	}
	else if (data->map[p_pose - 1] == 'N')
	{
		print_game_over();
		game_exit(data);
	}
	else if (data->map[p_pose - 1] == 'E')
		check_collect(data);
	fill_map(data, 'l');
	return (0);
}
