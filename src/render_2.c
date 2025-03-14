/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingjimen <ingjimen@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 10:29:54 by ingjimen          #+#    #+#             */
/*   Updated: 2025/03/13 10:34:30 by ingjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	print_exit(t_game *game, int x_pos, int y_pos)
{
	render_image(game, game->assets->e_curr_state, x_pos, y_pos);
}

static void	print_player(t_game *game)
{
	int	x_pos;
	int	y_pos;

	x_pos = (game->d->pos->x) * TILE_SIZE;
	y_pos = (game->d->pos->y) * TILE_SIZE;
	render_image(game, game->d->current_state, x_pos, y_pos);
}

void	render_dynamic_elements(t_game *game)
{
	int		y;
	int		x;

	y = 0;
	while (game->map_arr[y])
	{
		x = 0;
		while (game->map_arr[y][x])
		{
			if (game->map_arr[y][x] == 'E')
				print_exit(game, x * TILE_SIZE, y * TILE_SIZE);
			x++;
		}
		y++;
	}
	print_player(game);
}
