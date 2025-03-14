/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingjimen <ingjimen@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 10:00:36 by ingjimen          #+#    #+#             */
/*   Updated: 2025/03/13 10:02:59 by ingjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	validate_dragon_move(t_game *game, int x, int y)
{
	if (game->map_arr[y][x] == '1')
		return (0);
	else if (game->map_arr[y][x] == 'E' && game->c_count == 0)
	{
		return (game_won(game), 1);
	}
	else if (game->map_arr[y][x] == 'C')
	{
		game->map_arr[y][x] = '0';
		game->c_count--;
		if (game->c_count == 0)
			game->assets->e_curr_state = game->assets->exit_open;
	}
	return (1);
}
