/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 23:21:19 by hmrabet           #+#    #+#             */
/*   Updated: 2024/01/17 03:50:24 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "get_next_line.h"
# include <mlx.h>

# define GAME "so_long"
# define DIMENSION 60
# define P_DOWN "textures/p_down.xpm"
# define COLLECT "textures/collect.xpm"
# define WALL "textures/wall.xpm"
# define GROUND "textures/ground.xpm"
# define CLOSE_PORTAL "textures/close_portal.xpm"
# define OPEN_PORTAL "textures/open_portal.xpm"
# define WON1 " ___    ___ ________  ___  ___          ___"
# define WON1_1 "       __   ________  ________   ___\n"
# define WON2 " |\\  \\  /  /|\\   __  \\|\\  \\|\\  \\   "
# define WON2_1 "     |\\  \\     |\\  \\|\\   __  \\|\\"
# define WON3 "   ___  \\|\\  \\\n \\ \\  \\/  / | \\  \\|"
# define WON3_1 "\\  \\ \\  \\\\\\  \\       \\ \\  \\   "
# define WON4 " \\ \\  \\ \\  \\|\\  \\ \\  \\\\ \\  \\ \\"
# define WON4_1 "  \\\n  \\ \\    / / \\ \\  \\\\\\  \\ \\"
# define WON5 "  \\\\\\  \\       \\ \\  \\  __\\ \\  \\ \\"
# define WON5_1 "  \\\\\\  \\ \\  \\\\ \\  \\ \\  \\\n"
# define WON6 "   \\/  /  /   \\ \\  \\\\\\  \\ \\  \\\\\\"
# define WON6_1 "  \\       \\ \\  \\|\\__\\_\\  \\ \\  \\"
# define WON7 "\\\\  \\ \\  \\\\ \\  \\ \\__\\\n __/  / /  "
# define WON7_1 "    \\ \\_______\\ \\_______\\       \\ \\"
# define WON8 "____________\\ \\_______\\ \\__\\\\ \\__\\|__"
# define WON8_1 "|\n|\\___/ /        \\|_______|\\|_______|"
# define WON9 "        \\|____________|\\|_______|\\|__| "
# define WON9_1 "\\|__|   ___\n\\|___|/                       "
# define WON10 "                                          "
# define WON10_1 "          |\\__\\\n                          "
# define WON11 "                                          "
# define WON11_1 "              \\|__|\n"

typedef struct s_data
{
	void	*mlx;
	void	*mlx_win;
	char	*map;
	int		steps;
	void	*p_down;
	void	*collect;
	void	*wall;
	void	*ground;
	void	*close_portal;
	void	*open_portal;
	int		width;
	int		height;
}	t_data;

int		move_down(t_data *data);
int		move_up(t_data *data);
int		move_right(t_data *data);
int		move_left(t_data *data);
void	fill_map(t_data *data);
int		game_exit(t_data *data);
int		keys_events(int key, t_data *data);
char	*get_map(char *map);
int		parser(char *str);
int		path_finder(char *str);
void	free_buff(char	**rows);
void	ft_protection(t_data *data);

#endif
