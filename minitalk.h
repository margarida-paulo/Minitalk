#ifndef MINITALK_H
# define MINITALK_H

#include "libft/libft.h"
#include <signal.h>

int		ft_check_args(int argc, char *argv[]);
void		ft_bit_by_bit(char c, int pid);
void	ft_handle_signals(int signal);

# endif
