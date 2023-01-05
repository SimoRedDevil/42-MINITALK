/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yous <mel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:45:56 by mel-yous          #+#    #+#             */
/*   Updated: 2023/01/02 23:48:39 by mel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

char	*g_unicode;

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

static void	ft_fill_unicode(char *bits, int *r_bytes)
{
	if (!g_unicode)
		g_unicode = ft_strdup("");
	g_unicode = ft_strjoin(g_unicode, bits);
	if (!g_unicode)
	{
		ft_clear_unicode(r_bytes, &g_unicode);
		return ;
	}
	*r_bytes += 1;
}

static void	ft_handle_received_byte(int pid, char *bits, int *r_bytes)
{
	if (bits[0] == '1')
	{
		ft_fill_unicode(bits, r_bytes);
		ft_print_unicode(r_bytes, &g_unicode);
	}
	else if (bits[0] == '0')
	{
		ft_acknowledge(pid, bits);
		ft_putchar_fd(ft_binary2char(bits), 1);
	}
}

static void	siguser_handler(int sig, siginfo_t *info, void *context)
{
	static char	bits[9];
	static int	counter;
	static int	r_bytes;
	static int	prev_pid;

	(void)context;
	if (prev_pid > 0 && prev_pid != info->si_pid)
	{
		counter = 0;
		ft_bzero(bits, 8);
		ft_clear_unicode(&r_bytes, &g_unicode);
	}
	ft_fill_bits(sig, bits, &counter);
	if (counter == 8)
	{
		bits[counter] = '\0';
		ft_handle_received_byte((int)info->si_pid, bits, &r_bytes);
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
