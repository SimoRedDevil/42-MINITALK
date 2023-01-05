/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yous <mel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 11:27:11 by mel-yous          #+#    #+#             */
/*   Updated: 2023/01/01 21:44:34 by mel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	ft_power(int n1, int n2)
{
	int	result;

	result = 1;
	while (n2 > 0)
	{
		result *= n1;
		n2--;
	}
	return (result);
}

char	ft_binary2char(const char *binary)
{
	char	c;
	short	counter;

	c = '\0';
	counter = 7;
	while (*binary && counter >= 0)
	{
		if (*binary == '1')
			c += 1 * ft_power(2, counter);
		else
			c += 0;
		counter--;
		binary++;
	}
	return (c);
}

void	ft_send_signal(char c, int s_pid)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (((c >> i) & 1) == 0)
		{
			if (kill(s_pid, SIGUSR1) == -1)
				exit(1);
		}
		else
		{
			if (kill(s_pid, SIGUSR2) == -1)
				exit(1);
		}
		usleep(600);
		i--;
	}
}
