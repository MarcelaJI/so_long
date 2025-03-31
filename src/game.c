/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingjimen <ingjimen@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 08:35:32 by ingjimen          #+#    #+#             */
/*   Updated: 2025/03/17 08:26:30 by ingjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	begin_game(t_game *game)
{
	mlx_key_hook(game->mlx, handle_key_press, game);
	mlx_close_hook(game->mlx, handle_close_event, game);
	draw_game(game);
	mlx_loop(game->mlx);
}

int	close_game(t_game *game)
{
	ft_printf("%sTrust me, you can do it! \n%s", MAGENTA, RESET);
	free_mlx(game);
	free_game(&game);
	exit (0);
	return (0);
}

int	game_won(t_game *game)
{
	ft_printf("%sWinner! Great job💥\n%s", MAGENTA, RESET);
	free_mlx(game);
	free_game(&game);
	exit (0);
	return (0);
}
