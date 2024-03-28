/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalerio <mvalerio@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 12:59:53 by maggie            #+#    #+#             */
/*   Updated: 2024/03/28 21:48:15 by mvalerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

// There is a max_pid, check that
int	ft_check_args(int argc, char *argv[])
{
	int	pid;
	int	i;

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
			ft_printf("Invalid pid\n");
			return (0);
		}
		i++;
	}
	return (1);
}

void	ft_bit_by_bit(unsigned char c, int pid, int sleep)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (((c >> bit) & 1) == 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bit++;
		usleep(sleep);
	}
}

int	main(int argc, char *argv[])
{
	int		pid;
	size_t	i;
	int		length;
	int		sleep;

	if (!ft_check_args(argc, argv))
		return (0);
	pid = ft_atol(argv[1]);
	i = 0;
	length = ft_strlen(argv[2]);
	if (length <= 100)
		sleep = 100;
	else if (length <= 1000)
		sleep = 500;
	else
		sleep = 1000;
	while (argv[2][i])
	{
		ft_bit_by_bit(argv[2][i], pid, sleep);
		i++;
	}
	ft_bit_by_bit(argv[2][i], pid, sleep);
}
