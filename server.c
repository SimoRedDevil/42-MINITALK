/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yous <mel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 23:04:18 by mel-yous          #+#    #+#             */
/*   Updated: 2023/01/01 21:53:55 by mel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_fill_bits(int sig, char *bits, int *counter)
{
	if (sig == SIGUSR1)
	{
		bits[*counter] = '0';
		(*counter)++;
	}
	else if (sig == SIGUSR2)
	{
		bits[*counter] = '1';
		(*counter)++;
	}
}

static void	siguser_handler(int sig, siginfo_t *info, void *context)
{
	static char	bits[9];
	static int	counter;
	static int	prev_pid;

	(void)context;
	if (prev_pid > 0 && prev_pid != info->si_pid)
	{
		counter = 0;
		ft_bzero(bits, 8);
	}
	ft_fill_bits(sig, bits, &counter);
	if (counter == 8)
	{
		bits[counter] = '\0';
		ft_putchar_fd(ft_binary2char(bits), 1);
		counter = 0;
	}
	prev_pid = (int)info->si_pid;
}

int	main(void)
{
	int					pid;
	struct sigaction	s_action;

	pid = (int)getpid();
	ft_putstr_fd("--------------------------", 1);
	ft_putstr_fd("| Server PID => ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putstr_fd(" |--------------------------", 1);
	ft_putchar_fd('\n', 1);
	s_action.sa_flags = SA_SIGINFO;
	s_action.sa_sigaction = siguser_handler;
	sigaction(SIGUSR1, &s_action, NULL);
	sigaction(SIGUSR2, &s_action, NULL);
	while (1)
		pause();
}
