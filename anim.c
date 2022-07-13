/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekaik-ne <ekaik-ne@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 18:00:07 by ekaik-ne          #+#    #+#             */
/*   Updated: 2022/07/10 13:27:09 by ekaik-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	ft_open_door(t_game *game, int anim, int l)
{
	static int	x;
	static int	y;
	char		*file;

	if (x <= anim * 10)
	{
		if (y == 14 && game->open++)
		{
			mlx_destroy_image(game->link, game->img.exit);
			game->img.exit = mlx_xpm_file_to_image(game->link,
					"sprites/exit/DoorOpen.xpm", &l, &l);
		}
		else if (x++ % 10 == 0)
		{
			file = ft_get_xpm_file("sprites/exit/Door", y++);
			mlx_destroy_image(game->link, game->img.exit);
			game->img.exit = mlx_xpm_file_to_image(game->link, file, &l, &l);
			free(file);
		}
	}
	else
	{
		x = 1;
		y = 1;
	}
}

void	ft_anim_player(t_game *game, int anim, int l)
{
	static int	x;
	static int	y;
	char		*file;

	if (game->trap.player_trap == 1)
		ft_player_death(game, 8, 48);
	else if (x <= anim * 25)
	{
		if (y == 5)
			y = 0;
		else if (x++ % 25 == 0)
		{
			file = ft_get_xpm_file("sprites/player/Player", y++);
			mlx_destroy_image(game->link, game->img.player);
			game->img.player = mlx_xpm_file_to_image(game->link, file, &l, &l);
			free(file);
		}
	}
	else
	{
		x = 1;
		y = 1;
	}
}

void	ft_player_death(t_game *game, int anim, int l)
{
	static int	x;
	static int	y;
	char		*file;

	if (x <= anim * 25)
	{
		if (x++ % 25 == 0)
		{
			file = ft_get_xpm_file("sprites/player/Deaft", y++);
			mlx_destroy_image(game->link, game->img.player);
			game->img.player = mlx_xpm_file_to_image(game->link, file, &l, &l);
			free(file);
		}
	}
	else
	{
		x = 1;
		y = 0;
	}
	if (y == 8)
		ft_clear_window("Morreu\n", game);
}

void	ft_trap(t_game *game, int anim, int l)
{
	static int	x;
	char		*file;

	if (x <= anim * 50)
	{
		if (game->trap.count == 10)
			game->trap.count = 0;
		else if (x++ % 50 == 0)
		{
			if (game->trap.count <= 4)
				game->trap.check = 0;
			else
				game->trap.check = 1;
			file = ft_get_xpm_file("sprites/trap/Trap", game->trap.count++);
			mlx_destroy_image(game->link, game->trap.trap);
			game->trap.trap = mlx_xpm_file_to_image(game->link, file, &l, &l);
			free(file);
		}
	}
	else
	{
		x = 1;
		game->trap.count = 1;
	}
}

void	ft_anim_player_trap(t_game *game, int anim, int l)
{
	static int	x;
	char		*file;

	if (x <= anim * 28)
	{
		if (game->trap.t_count == 14)
			game->trap.t_count = 0;
		else if (x++ % 28 == 0)
		{
			if (game->trap.t_count <= 4)
				game->trap.t_check = 0;
			else
				game->trap.t_check = 1;
			file = ft_get_xpm_file("sprites/player/PlayerTrap",
					game->trap.t_count++);
			mlx_destroy_image(game->link, game->trap.t_trap);
			game->trap.t_trap = mlx_xpm_file_to_image(game->link, file, &l, &l);
			free(file);
		}
	}
	else
		x = 1;
	if (game->trap.t_count == 14)
		ft_clear_window("Died ;-;\n", game);
}
