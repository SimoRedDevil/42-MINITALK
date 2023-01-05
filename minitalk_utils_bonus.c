/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yous <mel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:48:23 by mel-yous          #+#    #+#             */
/*   Updated: 2023/01/03 00:19:30 by mel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

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

int	ft_send_signal(char c, int s_pid)
{
	int	i;
	int	bits_counter;

	i = 7;
	bits_counter = 0;
	while (i >= 0)
	{
		if (((c >> i) & 1) == 0)
		{
			if (kill(s_pid, SIGUSR1) == -1)
				exit(1);
			bits_counter++;
		}
		else
		{
			if (kill(s_pid, SIGUSR2) == -1)
				exit(1);
			bits_counter++;
		}
		usleep(600);
		i--;
	}
	return (bits_counter);
}

void	ft_clear_unicode(int *r_bytes, char **unicode)
{
	free(*unicode);
	*unicode = NULL;
	*r_bytes = 0;
}

void	ft_print_unicode(int *r_bytes, char **unicode)
{
	int		i;
	int		j;
	char	*curr_byte;

	i = 0;
	j = 0;
	while (*unicode && i < 4 && (*unicode)[i] == '1')
		i++;
	if (i == *r_bytes && *unicode)
	{
		i = 0;
		while (j <= 32)
		{
			if (j % 8 == 0)
			{
				curr_byte = ft_substr(*unicode, i, j);
				ft_putchar_fd(ft_binary2char(curr_byte), 1);
				i = j;
				free(curr_byte);
				curr_byte = NULL;
			}
			j++;
		}
		ft_clear_unicode(r_bytes, unicode);
	}
}
