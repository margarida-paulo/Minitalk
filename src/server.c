/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalerio <mvalerio@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 12:59:53 by maggie            #+#    #+#             */
/*   Updated: 2024/03/28 20:07:58 by mvalerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	ft_handle_signals(int signal)
{
	static int	pos = 0;
	static char	c;

	if (signal == SIGUSR1)
		c |= (1 << pos);
	pos++;
	if (pos == 8)
	{
		pos = 0;
		if (c == NULL)
			write(1, '\n', 1);
		else
			write(1, &c, 1);
		c = 0;
	}
}

int	main(void)
{
	ft_printf("The pid of your server is %d. Have fun!\n", getpid());
	signal(SIGUSR1, ft_handle_signals);
	signal(SIGUSR2, ft_handle_signals);
	while (1)
		pause();
	return (0);
}
