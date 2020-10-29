/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asegovia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 15:42:12 by asegovia          #+#    #+#             */
/*   Updated: 2019/12/12 14:49:48 by asegovia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		printp(t_struct *t)
{
	unsigned long	n;
	char			*str;

	t->i++;
	n = va_arg(t->arg, unsigned long);
	if (!n && t->wideflag < 2)
	{
		if (t->dotflag == 1 && t->wideflag < 2)
			t->wideflag = 2;
		str = "0x0";
		ft_putsstr(str, t);
		return ;
	}
	else
		str = ft_itoa_base(n, t);
	if (t->dotflag == 1 && t->wideflag < ft_strlen(str))
		t->wideflag = ft_strlen(str);
	ft_putsstr(str, t);
	free(str);
}

static char	*dotp(char *str, t_struct *t)
{
	char	*stro;
	int		i;

	i = t->wideflag - ft_strlen(str);
	if (i > 0)
	{
		if (!(stro = malloc(sizeof(char) * i + 1)))
			return (NULL);
		stro[i] = '\0';
		while (i-- != 0)
			stro[i] = '0';
		return (stro);
	}
	return ("");
}

char		*ft_itoa_base(unsigned long value, t_struct *t)
{
	char			*str;
	int				size;
	char			*tab;
	unsigned long	tmp;

	size = 0;
	tab = "0123456789abcdef";
	tmp = value;
	while (tmp /= 16)
		size++;
	size = size + 1;
	str = malloc(sizeof(char) * size + 1);
	str[size] = '\0';
	while (size > 0)
	{
		str[size - 1] = tab[value % 16];
		size--;
		value /= 16;
	}
	if (t->dotflag == 1)
		str = ft_strjoin(dotp(str, t), str);
	return (ft_strjoin("0x", str));
}
