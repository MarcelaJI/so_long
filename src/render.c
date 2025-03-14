/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingjimen <ingjimen@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 10:17:44 by ingjimen          #+#    #+#             */
/*   Updated: 2025/03/14 09:04:35 by ingjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	print_floor(t_game *game, int x_pos, int y_pos)
{
	char	**map_arr;

	map_arr = game->map_arr;
	if (map_arr[y_pos / TILE_SIZE][x_pos / TILE_SIZE] == 'P')
		map_arr[y_pos / TILE_SIZE][x_pos / TILE_SIZE] = '0';
	render_image(game, game->assets->floor, x_pos, y_pos);
}

static void	print_obst_and_colls(t_game *game, int x_pos, int y_pos)
{
	mlx_image_t	*obstacles[3];
	int			obst_idx;
	int			x;
	int			y;
	char		**map_arr;

	map_arr = game->map_arr;
	x = x_pos / TILE_SIZE;
	y = y_pos / TILE_SIZE;
	if (map_arr[y][x] == 'C')
		render_image(game, game->assets->coll, x_pos, y_pos);
	else
	{
		obstacles[0] = game->assets->obst_1;
		obstacles[1] = game->assets->obst_2;
		obstacles[2] = game->assets->obst_3;
		obst_idx = game->obstac_count % 3;
		game->obstac_count--;
		render_image(game, obstacles[obst_idx], x_pos, y_pos);
	}
}

static void	print_walls(t_game *game, int x_pos, int y_pos)
{
	int	x;
	int	y;

	x = x_pos / TILE_SIZE;
	y = y_pos / TILE_SIZE;
	if (x == 0 && y == 0)
		render_image(game, game->assets->wall_upper_l, x_pos, y_pos);
	else if (x == ((game->cols) - 1) && y == 0)
		render_image(game, game->assets->wall_upper_r, x_pos, y_pos);
	else if (x == 0 && y == ((game->rows) - 1))
		render_image(game, game->assets->wall_lower_l, x_pos, y_pos);
	else if (x == ((game->cols) - 1) && y == ((game->rows) - 1))
		render_image(game, game->assets->wall_lower_r, x_pos, y_pos);
	else if (x == 0 && (y > 0 && y < (game->rows) - 1))
		render_image(game, game->assets->wall_ver_l, x_pos, y_pos);
	else if (x == ((game->cols) - 1) && (y > 0 && y < (game->rows) - 1))
		render_image(game, game->assets->wall_ver_r, x_pos, y_pos);
	else if (y == 0 || y == ((game->rows) - 1))
		render_image(game, game->assets->wall_hor, x_pos, y_pos);
}

static void	initial_render(t_game *game)
{
	char		**map_arr;
	int			y;
	int			x;

	map_arr = game->map_arr;
	y = 0;
	while (map_arr[y])
	{
		x = 0;
		while (map_arr[y][x])
		{
			if (checkWall(game, x, y))
				print_walls(game, x * TILE_SIZE, y * TILE_SIZE);
			else if (map_arr[y][x] == '1' || map_arr[y][x] == 'C')
				print_obst_and_colls(game, x * TILE_SIZE, y * TILE_SIZE);
			else if (map_arr[y][x] == '0' || map_arr[y][x] == 'P')
				print_floor(game, x * TILE_SIZE, y * TILE_SIZE);
			x++;
		}
		y++;
	}
}

void	draw_game(t_game *game)
{
	initial_render(game);
	render_dynamic_elements(game);
}
