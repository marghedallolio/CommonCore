#include "push_swap.h"

int	sono_uguali(long nb, char **arg, int i)
{
	i++;
	while (arg[i])
	{
		if (ft_atol(arg[i]) == nb)
			return (1);
		i++;
	}
	return (0);
}

bool	is_num(char *num)
{
	int	i;

	if (!num || !num[0])
		return (false);
	i = 0;
	if (num[i] == '-' || num[i] == '+')
		i++;
	if (!num[i])
		return (false);
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (false);
		i++;
	}
	return (true);
}

void	check_arg(int ac, char **av)
{
	int			i;
	long int	tmp;
	char		**arg;

	i = 0;
	if (ac == 2)
		arg = ft_split(av[1], ' ');
	else
	{
		i = 1;
		arg = av;
	}
	while (arg[i])
	{
		if (!is_num(arg[i]))
			ft_error(arg, ac);
		tmp = ft_atol(arg[i]);
		if (tmp < INT_MIN || tmp > INT_MAX)
			ft_error(arg, ac);
		if (sono_uguali(tmp, arg, i))
			ft_error(arg, ac);
		i++;
	}
	if (ac == 2)
		ft_free(arg);
}

int	get_dist(t_node **lista, int i)
{
	int		distanza;
	t_node	*testa;

	testa = *lista;
	distanza = 0;
	while (testa)
	{
		if (testa->index == i)
			break ;
		distanza++;
		testa = testa->next;
	}
	return (distanza);
}

long int	ft_atol(const char *s)
{
	long int	res;
	int			sign;
	int			i;

	i = 0;
	res = 0;
	sign = 1;
	while (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13))
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		res = res * 10 + (s[i] - '0');
		i++;
	}
	return (res * sign);
}
