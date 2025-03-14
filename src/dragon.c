/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dragon.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingjimen <ingjimen@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 09:44:24 by ingjimen          #+#    #+#             */
/*   Updated: 2025/03/13 11:29:21 by ingjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

#define DELAY 2

static void	move_dragon(t_game *game, int x_new, int y_new)
{
	int			prev_x;
	int			prev_y;
	mlx_image_t	*floor;

	prev_x = game->d->pos->x;
	prev_y = game->d->pos->y;
	floor = game->assets->floor;
	if (validate_dragon_move(game, x_new, y_new))
	{
		render_image(game, floor, prev_x * TILE_SIZE, prev_y * TILE_SIZE);
		game->d->pos->x = x_new;
		game->d->pos->y = y_new;
		game->d->collect_count++;
		ft_printf("Steps: %d\n", game->d->collect_count);
		render_dynamic_elements(game);
	}
}

void	dragon_moves_press(struct mlx_key_data keydata, t_game *game)
{
	if (keydata.key == MLX_KEY_UP || keydata.key == MLX_KEY_W)
		move_dragon(game, game->d->pos->x, game->d->pos->y - 1);
	if (keydata.key == MLX_KEY_DOWN || keydata.key == MLX_KEY_S)
		move_dragon(game, game->d->pos->x, game->d->pos->y + 1);
	if (keydata.key == MLX_KEY_RIGHT || keydata.key == MLX_KEY_D)
	{
		game->d->current_state = game->d->dragon_right;
		move_dragon(game, game->d->pos->x + 1, game->d->pos->y);
	}
	if (keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_A)
	{
		game->d->current_state = game->d->dragon_left;
		move_dragon(game, game->d->pos->x - 1, game->d->pos->y);
	}
}

static void	update_counter(int key, int tar_key1, int tar_key2, int *counter)
{
	if (key == tar_key1 || key == tar_key2)
		(*counter)++;
	else
		*counter = 0;
}

static void	check_and_move(int *counter, const char *direction, t_game *game)
{
	if (*counter >= DELAY)
	{
		if (!ft_strncmp(direction, "UP", 2))
			move_dragon(game, game->d->pos->x, game->d->pos->y - 1);
		if (!ft_strncmp(direction, "DOWN", 4))
			move_dragon(game, game->d->pos->x, game->d->pos->y + 1);
		if (!ft_strncmp(direction, "RIGHT", 5))
		{
			game->d->current_state = game->d->dragon_right;
			move_dragon(game, game->d->pos->x + 1, game->d->pos->y);
		}
		if (!ft_strncmp(direction, "LEFT", 4))
		{
			game->d->current_state = game->d->dragon_left;
			move_dragon(game, game->d->pos->x - 1, game->d->pos->y);
		}
		*counter = 0;
	}
}

void	dragon_moves_hold(struct mlx_key_data keydata, t_game *game)
{
	static int	up_counter = 0;
	static int	down_counter = 0;
	static int	left_counter = 0;
	static int	right_counter = 0;

	update_counter(keydata.key, MLX_KEY_UP, MLX_KEY_W, &up_counter);
	update_counter(keydata.key, MLX_KEY_DOWN, MLX_KEY_S, &down_counter);
	update_counter(keydata.key, MLX_KEY_LEFT, MLX_KEY_A, &left_counter);
	update_counter(keydata.key, MLX_KEY_RIGHT, MLX_KEY_D, &right_counter);
	check_and_move(&up_counter, "UP", game);
	check_and_move(&down_counter, "DOWN", game);
	check_and_move(&left_counter, "LEFT", game);
	check_and_move(&right_counter, "RIGHT", game);
}
