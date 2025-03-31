/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asset_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingjimen <ingjimen@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 08:11:40 by ingjimen          #+#    #+#             */
/*   Updated: 2025/03/13 11:19:10 by ingjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	load_player_sprites(t_game *game)
{
	if (!import_image(game, &(game->d->dragon_right),
			"./assets/player_right.png"))
		return (0);
	if (!import_image(game, &(game->d->dragon_left),
			"./assets/player_left.png"))
		return (0);
	return (1);
}

static int	load_elements(t_game *game)
{
	mlx_image_t	**e_closed;

	e_closed = &(game->assets->exit_closed);
	if (!import_image(game, &(game->assets->coll), "./assets/coll.png"))
		return (0);
	if (!import_image(game, &(game->assets->exit_open), "./assets/e_open.png"))
		return (0);
	if (!import_image(game, e_closed, "./assets/e_closed.png"))
		return (0);
	if (!import_image(game, &(game->assets->obst_1), "./assets/obstacle_1.png"))
		return (0);
	if (!import_image(game, &(game->assets->obst_2), "./assets/obstacle_2.png"))
		return (0);
	if (!import_image(game, &(game->assets->obst_3), "./assets/obstacle_3.png"))
		return (0);
	game->assets->e_curr_state = game->assets->exit_closed;
	return (1);
}

static int	load_floor_tiles(t_game *game)
{
	if (!import_image(game, &(game->assets->floor), "./assets/floor.png"))
		return (0);
	return (1);
}

static int	load_walls(t_game *game)
{
	if (!import_image(game, &(game->assets->wall_hor),
			"./assets/wall_horizontal.png"))
		return (0);
	if (!import_image(game, &(game->assets->wall_ver_l),
			"./assets/wall_vertical_left.png"))
		return (0);
	if (!import_image(game, &(game->assets->wall_ver_r),
			"./assets/wall_vertical_right.png"))
		return (0);
	if (!import_image(game, &(game->assets->wall_lower_l),
			"./assets/wall_lower_left.png"))
		return (0);
	if (!import_image(game, &(game->assets->wall_lower_r),
			"./assets/wall_lower_right.png"))
		return (0);
	if (!import_image(game, &(game->assets->wall_upper_l),
			"./assets/wall_upper_left.png"))
		return (0);
	if (!import_image(game, &(game->assets->wall_upper_r),
			"./assets/wall_upper_right.png"))
		return (0);
	return (1);
}

int	load_game_images(t_game *game)
{
	if (!load_player_sprites(game))
		return (0);
	if (!load_floor_tiles(game))
		return (0);
	if (!load_walls(game))
		return (0);
	if (!load_elements(game))
		return (0);
	game->assets->e_curr_state = game->assets->exit_closed;
	return (1);
}
