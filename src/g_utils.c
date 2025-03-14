/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingjimen <ingjimen@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 08:42:10 by ingjimen          #+#    #+#             */
/*   Updated: 2025/03/13 08:53:23 by ingjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	game_init(t_game **game)
{
	t_dragon		*d;
	t_game_assets	*assets;
	t_pos			*d_pos;
	t_pos			*e_pos;

	d = NULL;
	assets = NULL;
	d_pos = NULL;
	e_pos = NULL;
	*game = (t_game *)malloc(sizeof(t_game));
	if (!*game)
		return ;
	d = (t_dragon *)malloc(sizeof(t_dragon));
	assets = (t_game_assets *)malloc(sizeof(t_game_assets));
	e_pos = (t_pos *)malloc(sizeof(t_pos));
	if (d)
		d_pos = (t_pos *)malloc(sizeof(t_pos));
	(*game)->d = d;
	(*game)->assets = assets;
	d->pos = d_pos;
	(*game)->e_pos = e_pos;
	(*game)->map_arr = NULL;
	(*game)->flood_visited = NULL;
	(*game)->d->collect_count = 0;
}

int	checkWall(t_game *game, int x, int y)
{
	if (x == 0
		|| y == 0
		|| x == ((game->cols) - 1)
		|| y == ((game->rows) - 1))
		return (1);
	return (0);
}
