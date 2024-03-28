/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalerio <mvalerio@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 12:59:53 by maggie            #+#    #+#             */
/*   Updated: 2024/03/28 19:00:31 by mvalerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

// There is a max_pid, check that
int	ft_check_args(int argc, char *argv[])
{
	int pid;
	int i;

	if (argc != 3)
	{
		ft_printf("Invalid number of arguments for Minitalk!");
		exit(1);
	}
	pid = ft_atol(argv[1]);
	i = 0;
	while (argv[1][i])
	{
		if (!ft_isdigit(argv[1][i]) || pid > 4194304 || pid <= 0)
		{
			ft_printf("%sInvalid pid%s\n");
			return (0);
		}
		i++;
	}
	return (1);
}

void	ft_bit_by_bit(char c, int pid)
{
	static int	bit = 0;

	if (bit < 8)
	{
		if ((c >> bit) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bit++;
	}
	else
		bit = 0;
	usleep(100);
}

int	main(int argc, char *argv[])
{
	int		pid;
	size_t	i;

	if (!ft_check_args(argc, argv))
		return (0);
	pid = ft_atol(argv[1]);
	kill(pid, SIGUSR1);
	i = 0;
	while (argv[2][i])
	{
		ft_bit_by_bit(argv[2][i], pid);
		i++;
	}
	ft_bit_by_bit(argv[2][i], pid);
}
