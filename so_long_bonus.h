/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 18:12:38 by hmrabet           #+#    #+#             */
/*   Updated: 2024/01/17 04:32:59 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "libft.h"
# include "get_next_line.h"
# include <mlx.h>
# include <time.h>

# define GAME "so_long"
# define DIMENSION 60
# define P_DOWN "textures/p_down.xpm"
# define P_UP "textures/p_up.xpm"
# define P_RIGHT "textures/p_right.xpm"
# define P_LEFT "textures/p_left.xpm"
# define ENNEMY "textures/ennemy.xpm"
# define GOLD_1 "textures/Gold_1.xpm"
# define GOLD_2 "textures/Gold_2.xpm"
# define GOLD_3 "textures/Gold_3.xpm"
# define GOLD_4 "textures/Gold_4.xpm"
# define GOLD_5 "textures/Gold_5.xpm"
# define GOLD_6 "textures/Gold_6.xpm"
# define GOLD_7 "textures/Gold_7.xpm"
# define GOLD_8 "textures/Gold_8.xpm"
# define GOLD_9 "textures/Gold_9.xpm"
# define GOLD_10 "textures/Gold_10.xpm"
# define GOLD_BANNER "textures/gold_banner.xpm"
# define STEPS_BANNER "textures/steps_banner.xpm"
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
# define OVER1 " ________  ________  _____ ______   _______"
# define OVER2 "           ________  ___      ___ _______   "
# define OVER3 "________  ___\n|\\   ____\\|\\   __  \\|\\   "
# define OVER4 "_ \\  _   \\|\\  ___ \\         |\\   __  \\|\\"
# define OVER5 "  \\    /  /|\\  ___ \\ |\\   __  \\|\\  \\\n\\ "
# define OVER6 "\\  \\___|\\ \\  \\|\\  \\ \\  \\\\\\__\\ \\  \\"
# define OVER7 " \\   __/|        \\ \\  \\|\\  \\ \\  \\  /  / |"
# define OVER8 " \\   __/|\\ \\  \\|\\  \\ \\  \\\n \\ \\  \\"
# define OVER10 "  __\\ \\   __  \\ \\  \\\\|__| \\  \\ \\  \\_|/__"
# define OVER11 "       \\ \\  \\\\\\  \\ \\  \\/  / / \\ \\  \\_|/_\\"
# define OVER12 " \\   _  _\\ \\  \\\n  \\ \\  \\|\\  \\ \\  \\ \\  \\"
# define OVER13 " \\  \\    \\ \\  \\ \\  \\_|\\ \\       \\ \\  \\\\\\"
# define OVER14 "  \\ \\    / /   \\ \\  \\_|\\ \\ \\  \\\\  \\\\ \\__\\"
# define OVER15 "\n   \\ \\_______\\ \\__\\ \\__\\ \\__\\    \\ \\__\\ \\"
# define OVER16 "_______\\       \\ \\_______\\ \\__/ /     \\ \\_______\\"
# define OVER17 " \\__\\\\ _\\\\|__|\n    \\|_______|\\|__|\\|__|\\|__|  "
# define OVER18 "   \\|__|\\|_______|        \\|_______|\\|__|/       \\|"
# define OVER19 "_______|\\|__|\\|__|   ___\n                              "
# define OVER20 "                                                       "
# define OVER21 "                 |\\__\\\n                                 "
# define OVER22 "                                                 "
# define OVER23 "                    \\|__|\n"

typedef struct s_data
{
	void	*mlx;
	void	*mlx_win;
	char	*map;
	int		steps;
	int		coins;
	void	*steps_banner;
	void	*gold_banner;
	void	*p_down;
	void	*p_up;
	void	*p_left;
	void	*p_right;
	void	*ennemy;
	void	*gold1;
	void	*gold2;
	void	*gold3;
	void	*gold4;
	void	*gold5;
	void	*gold6;
	void	*gold7;
	void	*gold8;
	void	*gold9;
	void	*gold10;
	void	*wall;
	void	*ground;
	void	*close_portal;
	void	*open_portal;
	int		width;
	int		height;
	clock_t	start;
}	t_data;

int		move_down(t_data *data);
int		move_up(t_data *data);
int		move_right(t_data *data);
int		move_left(t_data *data);
void	fill_map(t_data *data, char c);
int		game_exit(t_data *data);
int		keys_events(int key, t_data *data);
char	*get_map(char *map);
int		parser(char *str);
int		path_finder(char *str);
void	free_buff(char	**rows);
void	ft_protection(t_data *data);
int		coin_flip(t_data *data);
void	init_res(t_data *d);
void	destroy_images(t_data *data);
void	cleaning(t_data *data);
void	print_game_over(void);

#endif
