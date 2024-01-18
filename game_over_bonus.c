/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_over_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 04:02:47 by hmrabet           #+#    #+#             */
/*   Updated: 2024/01/17 04:14:39 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	print_game_over(void)
{
	ft_printf("\033[1;91m");
	ft_printf(OVER1 OVER2 OVER3 OVER4 OVER5);
	ft_printf(OVER6 OVER7 OVER8 OVER10);
	ft_printf(OVER11 OVER12 OVER13 OVER14 OVER15);
	ft_printf(OVER16 OVER17 OVER18 OVER19 OVER20);
	ft_printf(OVER21 OVER22 OVER23);
	ft_printf("\033[0m");
}
