/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yous <mel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:45:53 by mel-yous          #+#    #+#             */
/*   Updated: 2023/01/01 21:54:42 by mel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	g_sbits;

static void	ft_show_report(int sig)
{
	int		time_count;
	char	*time_unit;

	if ((g_sbits * 600) / 1000000 > 0)
	{
		time_count = (g_sbits * 600) / 1000000;
		time_unit = " seconds";
	}
	else
	{
		time_count = g_sbits * 600;
		time_unit = " ms";
	}
	(void)sig;
	ft_putstr_fd("------------------------------------------------------\n", 1);
	ft_putstr_fd("[+] The message has been sent successfully !\n", 1);
	ft_putstr_fd("[+] Time elapsed => ", 1);
	ft_putnbr_fd(time_count, 1);
	ft_putstr_fd(time_unit, 1);
	ft_putstr_fd("\n------------------------------------------------------", 1);
}

int	main(int argc, char **argv)
{
	int	server_pid;
	int	msg_len;
	int	i;

	if (argc == 3)
	{
		i = 0;
		server_pid = ft_atoi(argv[1]);
		if (server_pid <= 0)
		{
			ft_putstr_fd("The server PID is not valid !", 1);
			exit(1);
		}
		msg_len = (int)ft_strlen(argv[2]);
		signal(SIGUSR1, ft_show_report);
		while (msg_len >= 0)
		{
			g_sbits += ft_send_signal(argv[2][i], server_pid);
			i++;
			msg_len--;
		}
	}
}
