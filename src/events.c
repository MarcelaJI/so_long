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

void	handleKeyPress(struct mlx_key_data keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keydata.key == MLX_KEY_ESCAPE)
	{
		ft_printf("%sExit by pressing escape. \n%s", MAGENTA, RESET);
		close_game(game);
	}
	if (keydata.action == MLX_PRESS)
		dragon_moves_press(keydata, game);
	if (keydata.action == MLX_REPEAT)
		dragon_moves_hold(keydata, game);
}

void	handleCloseEvent(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (!game || !game->mlx)
	{
		print_error("game of mlx is NULL");
		return ;
	}
	ft_printf("%sExit by clicking close window button. \n%s", MAGENTA, RESET);
	close_game(game);
}
