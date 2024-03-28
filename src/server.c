/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalerio <mvalerio@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 12:59:53 by maggie            #+#    #+#             */
/*   Updated: 2024/03/28 19:03:58 by mvalerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	ft_handle_signals(int signal)
{
	static int	bit = 0;
	static char	c;
	char		operador;

	c = 0;
	operador = 0;
	if (bit < 7)
	{
        operador <<= bit;
        if (signal == SIGUSR1)
        {
            c |= operador;
        }
        bit++;
	}
	else
	{
		write(1, &c, 1);
		bit = 0;
		c = 0;
	}
}

int	main()
{
	ft_printf("The pid of your server is %d. Have fun!\n", getpid());
	signal(SIGUSR1, ft_handle_signals);
	signal(SIGUSR2, ft_handle_signals);
	while (1)
		pause();
	return (0);
}
