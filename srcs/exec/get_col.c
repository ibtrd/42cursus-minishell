/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_col.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 18:09:39 by kchillon          #+#    #+#             */
/*   Updated: 2024/04/14 18:26:28 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <termios.h>

static int	read_answer(char *buf)
{
	int		ret;
	int		i;
	char	ch;

	i = 0;
	ch = 0;
	while (ch != 'R')
	{
		ret = read(STDIN_FILENO, &ch, 1);
		if (!ret)
			return (-1);
		buf[i] = ch;
		i++;
	}
	return (i);
}

static int	parse_col(char *buf, int i)
{
	int	x;
	int	pow;

	x = 0;
	pow = 1;
	while (buf[i] != ';')
	{
		x = x + (buf[i] - '0') * pow;
		i--;
		pow *= 10;
	}
	return (x);
}

int	get_col(void)
{
	char			buf[30];
	int				i;
	int				ret;
	struct termios	term;
	struct termios	restore;

	tcgetattr(STDIN_FILENO, &term);
	tcgetattr(STDIN_FILENO, &restore);
	term.c_lflag &= ~(ICANON | ECHO);
	ret = tcsetattr(STDIN_FILENO, TCSANOW, &term) == -1;
	if (!ret)
		ret = write(1, "\033[6n", 4) != 4;
	i = 0;
	if (!ret)
		i = read_answer(buf);
	if (i < 2)
		ret = 1;
	if (!ret)
		i = parse_col(buf, i - 2);
	if (ret == -1)
		i = -1;
	ret |= (tcsetattr(STDIN_FILENO, TCSANOW, &restore) == -1) << 1;
	if (ret)
		return (-ret);
	return (i);
}
