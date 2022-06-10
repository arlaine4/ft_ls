# include "../includes/header.h"
# include "../ft_printf/includes/ft_printf.h"

int	main(int ac, char **av)
{
	(void)av;
	if (ac == 1)
		handle_no_args();
	else if (ac >= 2 && ac <= 3)
	{
		if (ac == 2)
			handle_double_args(av[1]);
		else if (ac == 3)
			handle_triple_args(av[1], av[2]);
	}
	return 0;
}
