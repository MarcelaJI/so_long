/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingjimen <ingjimen@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 09:39:59 by ingjimen          #+#    #+#             */
/*   Updated: 2025/03/14 09:02:59 by ingjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	handle_key_press(struct mlx_key_data keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keydata.key == MLX_KEY_ESCAPE)
	{
		ft_printf("%sPress ESC to exit. \n%s", MAGENTA, RESET);
		close_game(game);
	}
	if (keydata.action == MLX_PRESS)
		dragon_moves_press(keydata, game);
	if (keydata.action == MLX_REPEAT)
		dragon_moves_hold(keydata, game);
}

void	handle_close_event(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (!game || !game->mlx)
	{
		print_error("game of mlx is NULL");
		return ;
	}
	ft_printf("%sPress ✖ to rage quit! 🎮🔥 \n%s", MAGENTA, RESET);
	close_game(game);
}
